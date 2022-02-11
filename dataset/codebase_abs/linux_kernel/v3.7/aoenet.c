static int T_1 F_1 ( char * V_1 )
{
strncpy ( V_2 , V_1 , V_3 ) ;
V_2 [ V_3 - 1 ] = '\0' ;
return 1 ;
}
static int
F_2 ( void )
{
struct V_4 * V_5 ;
while ( ( V_5 = F_3 ( & V_6 ) ) ) {
F_4 ( & V_7 ) ;
F_5 ( V_5 ) ;
F_6 ( & V_7 ) ;
}
return 0 ;
}
int
F_7 ( struct V_8 * V_9 )
{
register char * V_10 , * V_11 ;
register int V_12 ;
if ( V_2 [ 0 ] == '\0' )
return 1 ;
V_10 = V_2 + strspn ( V_2 , V_13 ) ;
for (; * V_10 ; V_10 = V_11 + strspn ( V_11 , V_13 ) ) {
V_11 = V_10 + strcspn ( V_10 , V_13 ) ;
if ( V_11 != V_10 )
V_12 = V_11 - V_10 ;
else
V_12 = strlen ( V_10 ) ;
if ( strlen ( V_9 -> V_14 ) == V_12 && ! strncmp ( V_9 -> V_14 , V_10 , V_12 ) )
return 1 ;
if ( V_11 == V_10 )
break;
}
return 0 ;
}
int
F_8 ( const char T_2 * V_15 , T_3 V_16 )
{
if ( V_16 >= V_3 )
return - V_17 ;
if ( F_9 ( V_2 , V_15 , V_16 ) ) {
F_10 ( V_18 L_1 ) ;
return - V_19 ;
}
V_2 [ V_16 ] = 0x00 ;
return 0 ;
}
void
F_11 ( struct V_20 * V_21 )
{
struct V_4 * V_5 , * V_22 ;
T_4 V_23 ;
F_12 (queue, skb, tmp) {
F_13 ( V_5 , V_21 ) ;
F_14 ( & V_7 , V_23 ) ;
F_15 ( & V_6 , V_5 ) ;
F_16 ( & V_7 , V_23 ) ;
F_17 ( & V_24 ) ;
}
}
static int
F_18 ( struct V_4 * V_5 , struct V_8 * V_9 , struct V_25 * V_26 , struct V_8 * V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
T_5 V_32 ;
int V_33 ;
if ( F_19 ( V_9 ) != & V_34 )
goto exit;
V_5 = F_20 ( V_5 , V_35 ) ;
if ( V_5 == NULL )
return 0 ;
if ( ! F_7 ( V_9 ) )
goto exit;
F_21 ( V_5 , V_36 ) ;
V_33 = sizeof( * V_29 ) + sizeof( * V_31 ) ;
if ( V_5 -> V_12 >= V_33 ) {
V_33 -= F_22 ( V_5 ) ;
if ( V_33 > 0 && ! F_23 ( V_5 , V_33 ) )
goto exit;
}
V_29 = (struct V_28 * ) V_5 -> V_37 ;
V_32 = F_24 ( & V_29 -> V_38 ) ;
if ( ( V_29 -> V_39 & V_40 ) == 0 || ( V_32 & 1 << 31 ) )
goto exit;
if ( V_29 -> V_39 & V_41 ) {
V_32 = V_29 -> V_42 ;
if ( V_32 > V_43 )
V_32 = 0 ;
if ( F_25 () )
F_10 ( V_44
L_2 ,
L_3 ,
F_26 ( & V_29 -> V_45 ) ,
V_29 -> V_46 , V_5 -> V_47 -> V_14 ,
V_29 -> V_42 , V_48 [ V_32 ] ) ;
goto exit;
}
switch ( V_29 -> V_49 ) {
case V_50 :
V_5 = F_27 ( V_5 ) ;
break;
case V_51 :
F_28 ( V_5 ) ;
break;
default:
if ( V_29 -> V_49 >= V_52 )
break;
F_29 ( L_4 , V_29 -> V_49 ) ;
break;
}
if ( ! V_5 )
return 0 ;
exit:
F_30 ( V_5 ) ;
return 0 ;
}
int T_1
F_31 ( void )
{
F_32 ( & V_6 ) ;
F_33 ( & V_24 ) ;
F_34 ( & V_7 ) ;
V_53 . V_54 = & V_7 ;
V_53 . V_55 = F_2 ;
V_53 . V_56 = & V_24 ;
V_53 . V_14 = L_5 ;
if ( F_35 ( & V_53 ) )
return - V_57 ;
F_36 ( & V_58 ) ;
return 0 ;
}
void
F_37 ( void )
{
F_38 ( & V_53 ) ;
F_39 ( & V_6 ) ;
F_40 ( & V_58 ) ;
}
