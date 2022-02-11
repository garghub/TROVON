static int T_1 F_1 ( char * V_1 )
{
strncpy ( V_2 , V_1 , V_3 ) ;
V_2 [ V_3 - 1 ] = '\0' ;
return 1 ;
}
int
F_2 ( struct V_4 * V_5 )
{
register char * V_6 , * V_7 ;
register int V_8 ;
if ( V_2 [ 0 ] == '\0' )
return 1 ;
V_6 = V_2 + strspn ( V_2 , V_9 ) ;
for (; * V_6 ; V_6 = V_7 + strspn ( V_7 , V_9 ) ) {
V_7 = V_6 + strcspn ( V_6 , V_9 ) ;
if ( V_7 != V_6 )
V_8 = V_7 - V_6 ;
else
V_8 = strlen ( V_6 ) ;
if ( strlen ( V_5 -> V_10 ) == V_8 && ! strncmp ( V_5 -> V_10 , V_6 , V_8 ) )
return 1 ;
if ( V_7 == V_6 )
break;
}
return 0 ;
}
int
F_3 ( const char T_2 * V_11 , T_3 V_12 )
{
if ( V_12 >= V_3 )
return - V_13 ;
if ( F_4 ( V_2 , V_11 , V_12 ) ) {
F_5 ( V_14 L_1 ) ;
return - V_15 ;
}
V_2 [ V_12 ] = 0x00 ;
return 0 ;
}
void
F_6 ( struct V_16 * V_17 )
{
struct V_18 * V_19 , * V_20 ;
F_7 (queue, skb, tmp) {
F_8 ( V_19 , V_17 ) ;
F_9 ( V_19 ) ;
}
}
static int
F_10 ( struct V_18 * V_19 , struct V_4 * V_5 , struct V_21 * V_22 , struct V_4 * V_23 )
{
struct V_24 * V_25 ;
T_4 V_26 ;
if ( F_11 ( V_5 ) != & V_27 )
goto exit;
V_19 = F_12 ( V_19 , V_28 ) ;
if ( V_19 == NULL )
return 0 ;
if ( F_13 ( V_19 ) )
goto exit;
if ( ! F_2 ( V_5 ) )
goto exit;
F_14 ( V_19 , V_29 ) ;
V_25 = (struct V_24 * ) F_15 ( V_19 ) ;
V_26 = F_16 ( & V_25 -> V_30 ) ;
if ( ( V_25 -> V_31 & V_32 ) == 0 || ( V_26 & 1 << 31 ) )
goto exit;
if ( V_25 -> V_31 & V_33 ) {
V_26 = V_25 -> V_34 ;
if ( V_26 > V_35 )
V_26 = 0 ;
if ( F_17 () )
F_5 ( V_36
L_2 ,
L_3 ,
F_18 ( & V_25 -> V_37 ) ,
V_25 -> V_38 , V_19 -> V_39 -> V_10 ,
V_25 -> V_34 , V_40 [ V_26 ] ) ;
goto exit;
}
switch ( V_25 -> V_41 ) {
case V_42 :
F_19 ( V_19 ) ;
break;
case V_43 :
F_20 ( V_19 ) ;
break;
default:
if ( V_25 -> V_41 >= V_44 )
break;
F_5 ( V_14 L_4 , V_25 -> V_41 ) ;
}
exit:
F_21 ( V_19 ) ;
return 0 ;
}
int T_1
F_22 ( void )
{
F_23 ( & V_45 ) ;
return 0 ;
}
void
F_24 ( void )
{
F_25 ( & V_45 ) ;
}
