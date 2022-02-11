static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
T_1 V_6 ;
F_2 () ;
F_3 ( V_7 ) ;
V_6 = F_4 () + V_8 ;
F_5 () ;
while ( ! F_6 () ) {
F_7 () ;
F_8 () ;
if ( V_9 && F_4 () > V_6 )
break;
}
F_9 () ;
F_10 () ;
F_11 ( V_7 ) ;
F_12 () ;
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_5 () ;
F_14 () ;
F_10 () ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
unsigned long V_10 = F_16 ( V_11 ) ;
unsigned long V_12 ;
if ( F_17 ( V_13 < V_14 ) )
return V_5 ;
V_12 = V_10 ;
V_12 &= ~ V_15 ;
F_18 ( V_11 , V_12 ) ;
F_19 () ;
F_18 ( V_11 , V_10 ) ;
return V_5 ;
}
static int F_20 ( struct V_16 * V_17 ,
unsigned long V_18 , void * V_19 )
{
int V_20 = ( unsigned long ) V_19 ;
struct V_1 * V_2 =
F_21 ( V_21 , V_20 ) ;
if ( V_2 && F_22 () ) {
switch ( V_18 ) {
case V_22 :
case V_23 :
F_23 () ;
F_24 ( V_2 ) ;
F_25 () ;
break;
case V_24 :
case V_25 :
F_23 () ;
F_26 ( V_2 ) ;
F_25 () ;
break;
default:
return V_26 ;
}
}
return V_27 ;
}
static int F_27 ( void )
{
int V_28 ;
struct V_3 * V_4 = & V_29 ;
V_4 -> V_30 = 0 ;
for ( V_28 = 0 ; V_28 < V_31 ; ++ V_28 ) {
if ( V_32 [ V_28 ] . V_33 == NULL )
continue;
V_4 -> V_34 [ V_4 -> V_30 ] =
V_32 [ V_28 ] ;
V_4 -> V_30 += 1 ;
}
return 0 ;
}
static int F_28 ( void )
{
struct V_35 * V_36 ;
int V_37 = 1 ;
int V_38 ;
T_2 * V_39 , * V_40 , * V_41 ;
int V_42 , V_43 ;
V_36 = F_29 ( L_1 ) ;
if ( ! V_36 ) {
F_30 ( L_2 ) ;
goto V_44;
}
V_38 = F_31 ( V_36 , L_3 ) ;
if ( V_38 < 0 ) {
F_30 ( L_4 ) ;
goto V_44;
}
V_41 = F_32 ( sizeof( * V_41 ) * V_38 , V_45 ) ;
if ( F_33 ( V_36 ,
L_3 , V_41 , V_38 ) ) {
F_30 ( L_5 ) ;
goto V_46;
}
V_39 = F_32 ( sizeof( * V_39 ) * V_38 , V_45 ) ;
V_43 = F_33 ( V_36 ,
L_6 , V_39 , V_38 ) ;
if ( V_43 ) {
F_30 ( L_7 ) ;
goto V_47;
}
V_40 = F_32 ( sizeof( * V_40 ) * V_38 , V_45 ) ;
V_43 = F_33 ( V_36 ,
L_8 , V_40 , V_38 ) ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ ) {
if ( V_41 [ V_42 ] & V_48 ) {
strcpy ( V_49 [ V_37 ] . V_50 , L_9 ) ;
strcpy ( V_49 [ V_37 ] . V_51 , L_9 ) ;
V_49 [ V_37 ] . V_41 = 0 ;
V_49 [ V_37 ] . V_52 = 100 ;
V_49 [ V_37 ] . V_33 = & F_13 ;
}
#ifdef F_34
if ( V_41 [ V_42 ] & V_53 ||
V_41 [ V_42 ] & V_54 ) {
strcpy ( V_49 [ V_37 ] . V_50 , L_10 ) ;
strcpy ( V_49 [ V_37 ] . V_51 , L_10 ) ;
V_49 [ V_37 ] . V_41 = V_55 ;
V_49 [ V_37 ] . V_52 = 300000 ;
V_49 [ V_37 ] . V_33 = & F_15 ;
}
#endif
V_49 [ V_37 ] . V_56 =
( ( unsigned int ) V_39 [ V_42 ] ) / 1000 ;
if ( ! V_43 ) {
V_49 [ V_37 ] . V_52 =
( ( unsigned int ) V_40 [ V_42 ] ) / 1000 ;
}
V_37 ++ ;
}
F_35 ( V_40 ) ;
V_47:
F_35 ( V_39 ) ;
V_46:
F_35 ( V_41 ) ;
V_44:
return V_37 ;
}
static int F_36 ( void )
{
if ( V_57 != V_58 )
return - V_59 ;
if ( F_37 ( V_60 ) ) {
V_32 = V_49 ;
V_31 = F_28 () ;
if ( V_31 > 1 ) {
V_9 = true ;
V_8 = V_49 [ 1 ] . V_52 *
V_61 ;
}
} else
return - V_59 ;
return 0 ;
}
static int T_3 F_38 ( void )
{
int V_62 ;
V_62 = F_36 () ;
if ( V_62 )
return V_62 ;
F_27 () ;
V_62 = F_39 ( & V_29 , NULL ) ;
if ( V_62 ) {
F_40 ( V_63 L_11 ) ;
return V_62 ;
}
F_41 ( & V_64 ) ;
F_40 ( V_63 L_12 ) ;
return 0 ;
}
