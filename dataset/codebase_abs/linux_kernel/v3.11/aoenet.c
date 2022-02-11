static int T_1 F_1 ( char * V_1 )
{
strncpy ( V_2 , V_1 , V_3 ) ;
V_2 [ V_3 - 1 ] = '\0' ;
return 1 ;
}
static int
F_2 ( int V_4 ) __must_hold( &txlock
int
F_3 ( struct V_5 * V_6 )
{
register char * V_7 , * V_8 ;
register int V_9 ;
if ( V_2 [ 0 ] == '\0' )
return 1 ;
V_7 = V_2 + strspn ( V_2 , V_10 ) ;
for (; * V_7 ; V_7 = V_8 + strspn ( V_8 , V_10 ) ) {
V_8 = V_7 + strcspn ( V_7 , V_10 ) ;
if ( V_8 != V_7 )
V_9 = V_8 - V_7 ;
else
V_9 = strlen ( V_7 ) ;
if ( strlen ( V_6 -> V_11 ) == V_9 && ! strncmp ( V_6 -> V_11 , V_7 , V_9 ) )
return 1 ;
if ( V_8 == V_7 )
break;
}
return 0 ;
}
int
F_4 ( const char T_2 * V_12 , T_3 V_13 )
{
if ( V_13 >= V_3 )
return - V_14 ;
if ( F_5 ( V_2 , V_12 , V_13 ) ) {
F_6 ( V_15 L_1 ) ;
return - V_16 ;
}
V_2 [ V_13 ] = 0x00 ;
return 0 ;
}
void
F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 , * V_21 ;
T_4 V_22 ;
F_8 (queue, skb, tmp) {
F_9 ( V_20 , V_18 ) ;
F_10 ( & V_23 , V_22 ) ;
F_11 ( & V_24 , V_20 ) ;
F_12 ( & V_23 , V_22 ) ;
F_13 ( & V_25 ) ;
}
}
static int
F_14 ( struct V_19 * V_20 , struct V_5 * V_6 , struct V_26 * V_27 , struct V_5 * V_28 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
T_5 V_33 ;
int V_34 ;
if ( F_15 ( V_6 ) != & V_35 )
goto exit;
V_20 = F_16 ( V_20 , V_36 ) ;
if ( V_20 == NULL )
return 0 ;
if ( ! F_3 ( V_6 ) )
goto exit;
F_17 ( V_20 , V_37 ) ;
V_34 = sizeof( * V_30 ) + sizeof( * V_32 ) ;
if ( V_20 -> V_9 >= V_34 ) {
V_34 -= F_18 ( V_20 ) ;
if ( V_34 > 0 && ! F_19 ( V_20 , V_34 ) )
goto exit;
}
V_30 = (struct V_29 * ) V_20 -> V_38 ;
V_33 = F_20 ( & V_30 -> V_39 ) ;
if ( ( V_30 -> V_40 & V_41 ) == 0 || ( V_33 & 1 << 31 ) )
goto exit;
if ( V_30 -> V_40 & V_42 ) {
V_33 = V_30 -> V_43 ;
if ( V_33 > V_44 )
V_33 = 0 ;
if ( F_21 () )
F_6 ( V_45
L_2 ,
L_3 ,
F_22 ( & V_30 -> V_46 ) ,
V_30 -> V_47 , V_20 -> V_48 -> V_11 ,
V_30 -> V_43 , V_49 [ V_33 ] ) ;
goto exit;
}
switch ( V_30 -> V_50 ) {
case V_51 :
V_20 = F_23 ( V_20 ) ;
break;
case V_52 :
F_24 ( V_20 ) ;
break;
default:
if ( V_30 -> V_50 >= V_53 )
break;
F_25 ( L_4 , V_30 -> V_50 ) ;
break;
}
if ( ! V_20 )
return 0 ;
exit:
F_26 ( V_20 ) ;
return 0 ;
}
int T_1
F_27 ( void )
{
F_28 ( & V_24 ) ;
F_29 ( & V_25 ) ;
F_30 ( & V_23 ) ;
V_54 . V_55 = & V_23 ;
V_54 . V_56 = F_2 ;
V_54 . V_57 = & V_25 ;
V_54 . V_4 = 0 ;
snprintf ( V_54 . V_11 , sizeof( V_54 . V_11 ) , L_5 , V_54 . V_4 ) ;
if ( F_31 ( & V_54 ) )
return - V_58 ;
F_32 ( & V_59 ) ;
return 0 ;
}
void
F_33 ( void )
{
F_34 ( & V_54 ) ;
F_35 ( & V_24 ) ;
F_36 ( & V_59 ) ;
}
