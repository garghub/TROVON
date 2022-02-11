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
V_9 &= ~ V_12 ;
F_17 ( V_8 , V_9 ) ;
F_18 () ;
F_17 ( V_8 , V_7 ) ;
return V_5 ;
}
static int F_19 ( struct V_13 * V_14 ,
unsigned long V_15 , void * V_16 )
{
int V_17 = ( unsigned long ) V_16 ;
struct V_1 * V_2 =
F_20 ( V_18 , V_17 ) ;
if ( V_2 && F_21 () ) {
switch ( V_15 ) {
case V_19 :
case V_20 :
F_22 () ;
F_23 ( V_2 ) ;
F_24 () ;
break;
case V_21 :
case V_22 :
F_22 () ;
F_25 ( V_2 ) ;
F_24 () ;
break;
default:
return V_23 ;
}
}
return V_24 ;
}
static int F_26 ( void )
{
int V_25 ;
struct V_3 * V_4 = & V_26 ;
V_4 -> V_27 = 0 ;
for ( V_25 = 0 ; V_25 < V_28 ; ++ V_25 ) {
if ( V_29 [ V_25 ] . V_30 == NULL )
continue;
V_4 -> V_31 [ V_4 -> V_27 ] =
V_29 [ V_25 ] ;
V_4 -> V_27 += 1 ;
}
return 0 ;
}
static int F_27 ( void )
{
struct V_32 * V_33 ;
int V_34 = 1 ;
int V_35 ;
const T_1 * V_36 ;
T_2 V_37 , V_38 ;
int V_39 ;
V_33 = F_28 ( L_1 ) ;
if ( ! V_33 ) {
F_29 ( L_2 ) ;
return V_34 ;
}
V_36 = F_30 ( V_33 , L_3 , & V_37 ) ;
if ( ! V_36 ) {
F_29 ( L_4 ) ;
return V_34 ;
}
V_35 = V_37 / sizeof( T_2 ) ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 ++ ) {
V_38 = F_31 ( V_36 [ V_39 ] ) ;
if ( V_38 & V_40 ) {
strcpy ( V_41 [ V_34 ] . V_42 , L_5 ) ;
strcpy ( V_41 [ V_34 ] . V_43 , L_5 ) ;
V_41 [ V_34 ] . V_38 = V_44 ;
V_41 [ V_34 ] . V_45 = 10 ;
V_41 [ V_34 ] . V_46 = 100 ;
V_41 [ V_34 ] . V_30 = & F_12 ;
V_34 ++ ;
}
if ( V_38 & V_47 ) {
strcpy ( V_41 [ V_34 ] . V_42 , L_6 ) ;
strcpy ( V_41 [ V_34 ] . V_43 , L_6 ) ;
V_41 [ V_34 ] . V_38 =
V_44 | V_48 ;
V_41 [ V_34 ] . V_45 = 300 ;
V_41 [ V_34 ] . V_46 = 1000000 ;
V_41 [ V_34 ] . V_30 = & F_14 ;
V_34 ++ ;
}
}
return V_34 ;
}
static int F_32 ( void )
{
if ( V_49 != V_50 )
return - V_51 ;
if ( F_33 ( V_52 ) ) {
V_29 = V_41 ;
V_28 = F_27 () ;
} else
return - V_51 ;
return 0 ;
}
static int T_3 F_34 ( void )
{
int V_53 ;
V_53 = F_32 () ;
if ( V_53 )
return V_53 ;
F_26 () ;
V_53 = F_35 ( & V_26 , NULL ) ;
if ( V_53 ) {
F_36 ( V_54 L_7 ) ;
return V_53 ;
}
F_37 ( & V_55 ) ;
F_36 ( V_54 L_8 ) ;
return 0 ;
}
