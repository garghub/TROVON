static int T_1 F_1 ( char * V_1 )
{
strncpy ( V_2 , V_1 , V_3 ) ;
V_2 [ V_3 - 1 ] = '\0' ;
return 1 ;
}
static int
F_2 ( void ) __must_hold( &txlock
int
F_3 ( struct V_4 * V_5 )
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
F_4 ( const char T_2 * V_11 , T_3 V_12 )
{
if ( V_12 >= V_3 )
return - V_13 ;
if ( F_5 ( V_2 , V_11 , V_12 ) ) {
F_6 ( V_14 L_1 ) ;
return - V_15 ;
}
V_2 [ V_12 ] = 0x00 ;
return 0 ;
}
void
F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_19 , * V_20 ;
T_4 V_21 ;
F_8 (queue, skb, tmp) {
F_9 ( V_19 , V_17 ) ;
F_10 ( & V_22 , V_21 ) ;
F_11 ( & V_23 , V_19 ) ;
F_12 ( & V_22 , V_21 ) ;
F_13 ( & V_24 ) ;
}
}
static int
F_14 ( struct V_18 * V_19 , struct V_4 * V_5 , struct V_25 * V_26 , struct V_4 * V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
T_5 V_32 ;
int V_33 ;
if ( F_15 ( V_5 ) != & V_34 )
goto exit;
V_19 = F_16 ( V_19 , V_35 ) ;
if ( V_19 == NULL )
return 0 ;
if ( ! F_3 ( V_5 ) )
goto exit;
F_17 ( V_19 , V_36 ) ;
V_33 = sizeof( * V_29 ) + sizeof( * V_31 ) ;
if ( V_19 -> V_8 >= V_33 ) {
V_33 -= F_18 ( V_19 ) ;
if ( V_33 > 0 && ! F_19 ( V_19 , V_33 ) )
goto exit;
}
V_29 = (struct V_28 * ) V_19 -> V_37 ;
V_32 = F_20 ( & V_29 -> V_38 ) ;
if ( ( V_29 -> V_39 & V_40 ) == 0 || ( V_32 & 1 << 31 ) )
goto exit;
if ( V_29 -> V_39 & V_41 ) {
V_32 = V_29 -> V_42 ;
if ( V_32 > V_43 )
V_32 = 0 ;
if ( F_21 () )
F_6 ( V_44
L_2 ,
L_3 ,
F_22 ( & V_29 -> V_45 ) ,
V_29 -> V_46 , V_19 -> V_47 -> V_10 ,
V_29 -> V_42 , V_48 [ V_32 ] ) ;
goto exit;
}
switch ( V_29 -> V_49 ) {
case V_50 :
V_19 = F_23 ( V_19 ) ;
break;
case V_51 :
F_24 ( V_19 ) ;
break;
default:
if ( V_29 -> V_49 >= V_52 )
break;
F_25 ( L_4 , V_29 -> V_49 ) ;
break;
}
if ( ! V_19 )
return 0 ;
exit:
F_26 ( V_19 ) ;
return 0 ;
}
int T_1
F_27 ( void )
{
F_28 ( & V_23 ) ;
F_29 ( & V_24 ) ;
F_30 ( & V_22 ) ;
V_53 . V_54 = & V_22 ;
V_53 . V_55 = F_2 ;
V_53 . V_56 = & V_24 ;
V_53 . V_10 = L_5 ;
if ( F_31 ( & V_53 ) )
return - V_57 ;
F_32 ( & V_58 ) ;
return 0 ;
}
void
F_33 ( void )
{
F_34 ( & V_53 ) ;
F_35 ( & V_23 ) ;
F_36 ( & V_58 ) ;
}
