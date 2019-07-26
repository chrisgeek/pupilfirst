[@bs.config {jsx: 3}];

type props = {
  schoolName: string,
  authenticityToken: string,
  fqdn: string,
  oauthHost: string,
};

let decodeProps = json =>
  Json.Decode.{
    schoolName: json |> field("schoolName", string),
    authenticityToken: json |> field("authenticityToken", string),
    fqdn: json |> field("fqdn", string),
    oauthHost: json |> field("oauthHost", string),
  };

let props =
  DomUtils.parseJsonAttribute(
    ~id="user-session-new",
    ~attribute="data-json-props",
    (),
  )
  |> decodeProps;

ReactDOMRe.renderToElementWithId(
  <UserSessionNew
    schoolName={props.schoolName}
    authenticityToken={props.authenticityToken}
    fqdn={props.fqdn}
    oauthHost={props.oauthHost}
  />,
  "user-session-new",
);
