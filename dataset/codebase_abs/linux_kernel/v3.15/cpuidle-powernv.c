static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_2 () ;
F_3 ( V_6 ) ;
F_4 () ;
while ( ! F_5 () ) {
F_6 () ;
F_7 () ;
}
F_8 () ;
F_9 () ;
F_10 ( V_6 ) ;
F_11 () ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_4 () ;
F_13 () ;
F_9 () ;
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
unsigned long V_7 = F_15 ( V_8 ) ;
unsigned long V_9 ;
if ( F_16 ( V_10 < V_11 ) )
return V_5 ;
V_9 = V_7 ;
V_9 &= ~ ( V_12 | V_13 ) ;
V_9 |= V_14 ;
F_17 ( V_8 , V_9 ) ;
F_18 () ;
F_17 ( V_8 , V_7 ) ;
return V_5 ;
}
static int F_19 ( struct V_15 * V_16 ,
unsigned long V_17 , void * V_18 )
{
int V_19 = ( unsigned long ) V_18 ;
struct V_1 * V_2 =
F_20 ( V_20 , V_19 ) ;
if ( V_2 && F_21 () ) {
switch ( V_17 ) {
case V_21 :
case V_22 :
F_22 () ;
F_23 ( V_2 ) ;
F_24 () ;
break;
case V_23 :
case V_24 :
F_22 () ;
F_25 ( V_2 ) ;
F_24 () ;
break;
default:
return V_25 ;
}
}
return V_26 ;
}
static int F_26 ( void )
{
int V_27 ;
struct V_3 * V_4 = & V_28 ;
V_4 -> V_29 = 0 ;
for ( V_27 = 0 ; V_27 < V_30 ; ++ V_27 ) {
if ( V_31 [ V_27 ] . V_32 == NULL )
continue;
V_4 -> V_33 [ V_4 -> V_29 ] =
V_31 [ V_27 ] ;
V_4 -> V_29 += 1 ;
}
return 0 ;
}
static int F_27 ( void )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_38 = 1 ;
int V_39 ;
T_1 * V_40 ;
int V_41 ;
V_35 = F_28 ( L_1 ) ;
if ( ! V_35 ) {
F_29 ( L_2 ) ;
return V_38 ;
}
V_37 = F_30 ( V_35 , L_3 , NULL ) ;
if ( ! V_37 ) {
F_29 ( L_4 ) ;
return V_38 ;
}
V_39 = V_37 -> V_42 / sizeof( T_1 ) ;
V_40 = ( T_1 * ) V_37 -> V_43 ;
for ( V_41 = 0 ; V_41 < V_39 ; V_41 ++ ) {
if ( V_40 [ V_41 ] & V_44 ) {
strcpy ( V_45 [ V_38 ] . V_46 , L_5 ) ;
strcpy ( V_45 [ V_38 ] . V_47 , L_5 ) ;
V_45 [ V_38 ] . V_40 = V_48 ;
V_45 [ V_38 ] . V_49 = 10 ;
V_45 [ V_38 ] . V_50 = 100 ;
V_45 [ V_38 ] . V_32 = & F_12 ;
V_38 ++ ;
}
if ( V_40 [ V_41 ] & V_51 ) {
strcpy ( V_45 [ V_38 ] . V_46 , L_6 ) ;
strcpy ( V_45 [ V_38 ] . V_47 , L_6 ) ;
V_45 [ V_38 ] . V_40 =
V_48 | V_52 ;
V_45 [ V_38 ] . V_49 = 300 ;
V_45 [ V_38 ] . V_50 = 1000000 ;
V_45 [ V_38 ] . V_32 = & F_14 ;
V_38 ++ ;
}
}
return V_38 ;
}
static int F_31 ( void )
{
if ( V_53 != V_54 )
return - V_55 ;
if ( F_32 ( V_56 ) ) {
V_31 = V_45 ;
V_30 = F_27 () ;
} else
return - V_55 ;
return 0 ;
}
static int T_2 F_33 ( void )
{
int V_57 ;
V_57 = F_31 () ;
if ( V_57 )
return V_57 ;
F_26 () ;
V_57 = F_34 ( & V_28 , NULL ) ;
if ( V_57 ) {
F_35 ( V_58 L_7 ) ;
return V_57 ;
}
F_36 ( & V_59 ) ;
F_35 ( V_58 L_8 ) ;
return 0 ;
}
