int F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 >= V_4 )
return - V_5 ;
return ( F_2 ( ( const struct V_1 * * ) & V_6 [ V_3 ] , NULL , V_2 ) == NULL ) ?
0 : - V_7 ;
}
int F_3 ( const struct V_1 * V_2 , T_1 V_3 )
{
int V_8 ;
if ( V_3 >= V_4 )
return - V_5 ;
V_8 = ( F_2 ( ( const struct V_1 * * ) & V_6 [ V_3 ] , V_2 , NULL ) == V_2 ) ?
0 : - V_7 ;
if ( V_8 )
return V_8 ;
F_4 () ;
return 0 ;
}
void F_5 ( struct V_9 * V_10 , const struct V_11 * V_12 ,
int V_13 )
{
struct V_14 * V_15 ;
F_6 ( V_10 , V_13 ) ;
V_15 = (struct V_14 * ) V_10 -> V_16 ;
V_15 -> V_17 = F_7 ( V_12 -> V_17 ) ;
V_15 -> V_18 = V_12 -> V_2 ;
if ( V_12 -> V_17 & ( V_19 | V_20 | V_21 ) ) {
T_2 * V_22 = ( T_2 * ) ( ( ( T_1 * ) V_15 ) + V_13 - 4 ) ;
if ( V_12 -> V_17 & V_21 ) {
* V_22 = V_12 -> V_23 ;
V_22 -- ;
}
if ( V_12 -> V_17 & V_19 ) {
* V_22 = V_12 -> V_24 ;
V_22 -- ;
}
if ( V_12 -> V_17 & V_20 &&
! ( F_8 ( V_10 ) -> V_25 & V_26 ) ) {
* V_22 = 0 ;
* ( V_27 * ) V_22 = F_9 ( F_10 ( V_10 , 0 ,
V_10 -> V_28 , 0 ) ) ;
}
}
}
static V_27 F_11 ( struct V_9 * V_10 )
{
V_27 V_29 = 0 ;
switch ( V_10 -> V_30 ) {
case V_31 :
V_29 = F_9 ( V_10 -> V_29 ) ;
if ( ! V_29 )
break;
case V_32 :
V_10 -> V_29 = 0 ;
V_29 = F_12 ( V_10 ) ;
V_10 -> V_30 = V_31 ;
break;
}
return V_29 ;
}
static int F_13 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool * V_33 )
{
unsigned int V_34 = F_14 ( V_10 ) ;
const struct V_14 * V_15 ;
T_2 * V_35 ;
int V_13 ;
if ( F_15 ( ! F_16 ( V_10 , sizeof( struct V_14 ) ) ) )
return - V_5 ;
V_15 = (struct V_14 * ) ( F_17 ( V_10 ) + V_34 ) ;
if ( F_15 ( V_15 -> V_17 & ( V_36 | V_37 ) ) )
return - V_5 ;
V_12 -> V_17 = F_18 ( V_15 -> V_17 ) ;
V_13 = F_19 ( V_12 -> V_17 ) ;
if ( ! F_16 ( V_10 , V_13 ) )
return - V_5 ;
V_15 = (struct V_14 * ) ( F_17 ( V_10 ) + V_34 ) ;
V_12 -> V_2 = V_15 -> V_18 ;
V_35 = ( T_2 * ) ( V_15 + 1 ) ;
if ( V_15 -> V_17 & V_38 ) {
if ( F_11 ( V_10 ) ) {
* V_33 = true ;
return - V_5 ;
}
V_35 ++ ;
}
if ( V_15 -> V_17 & V_39 ) {
V_12 -> V_24 = * V_35 ;
V_35 ++ ;
} else
V_12 -> V_24 = 0 ;
if ( F_15 ( V_15 -> V_17 & V_40 ) ) {
V_12 -> V_23 = * V_35 ;
V_35 ++ ;
} else
V_12 -> V_23 = 0 ;
if ( V_15 -> V_17 == 0 && V_12 -> V_2 == F_20 ( V_41 ) ) {
V_12 -> V_2 = F_20 ( V_42 ) ;
if ( ( * ( T_1 * ) V_35 & 0xF0 ) != 0x40 ) {
V_13 += 4 ;
if ( ! F_16 ( V_10 , V_13 ) )
return - V_5 ;
}
}
return F_21 ( V_10 , V_13 , V_12 -> V_2 ) ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
int V_43 ;
bool V_33 = false ;
#ifdef F_23
if ( F_24 ( F_25 ( V_10 ) -> V_44 ) ) {
if ( F_26 ( F_27 ( V_10 ) ) )
goto V_45;
}
#endif
if ( F_13 ( V_10 , & V_12 , & V_33 ) < 0 )
goto V_45;
F_28 () ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ ) {
struct V_47 * V_2 ;
int V_8 ;
V_2 = F_29 ( V_48 [ V_43 ] ) ;
if ( ! V_2 )
continue;
V_8 = V_2 -> V_49 ( V_10 , & V_12 ) ;
if ( V_8 == V_50 ) {
F_30 () ;
return 0 ;
}
}
F_30 () ;
F_31 ( V_10 , V_51 , V_52 , 0 ) ;
V_45:
F_32 ( V_10 ) ;
return 0 ;
}
static void F_33 ( struct V_9 * V_10 , T_3 V_53 )
{
const int type = F_34 ( V_10 ) -> type ;
const int V_54 = F_34 ( V_10 ) -> V_54 ;
struct V_11 V_12 ;
bool V_33 = false ;
int V_43 ;
if ( F_13 ( V_10 , & V_12 , & V_33 ) ) {
if ( ! V_33 )
return;
}
if ( type == V_51 && V_54 == V_55 ) {
F_35 ( V_10 , F_36 ( V_10 -> V_56 ) , V_53 ,
V_10 -> V_56 -> V_57 , 0 , V_58 , 0 ) ;
return;
}
if ( type == V_59 ) {
F_37 ( V_10 , F_36 ( V_10 -> V_56 ) , V_10 -> V_56 -> V_57 , 0 ,
V_58 , 0 ) ;
return;
}
F_28 () ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ ) {
struct V_47 * V_2 ;
V_2 = F_29 ( V_48 [ V_43 ] ) ;
if ( ! V_2 )
continue;
if ( V_2 -> V_60 ( V_10 , V_53 , & V_12 ) == V_50 )
goto V_61;
}
V_61:
F_30 () ;
}
static int F_38 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 ;
T_1 V_62 ;
int V_8 ;
if ( ! F_16 ( V_10 , 12 ) )
goto V_45;
V_62 = V_10 -> V_16 [ 1 ] & 0x7f ;
if ( V_62 >= V_4 )
goto V_45;
F_28 () ;
V_2 = F_29 ( V_6 [ V_62 ] ) ;
if ( ! V_2 || ! V_2 -> V_49 )
goto V_63;
V_8 = V_2 -> V_49 ( V_10 ) ;
F_30 () ;
return V_8 ;
V_63:
F_30 () ;
V_45:
F_32 ( V_10 ) ;
return V_64 ;
}
static void F_39 ( struct V_9 * V_10 , T_3 V_53 )
{
const struct V_1 * V_2 ;
const struct V_65 * V_66 = ( const struct V_65 * ) V_10 -> V_16 ;
T_1 V_62 = V_10 -> V_16 [ ( V_66 -> V_67 << 2 ) + 1 ] & 0x7f ;
if ( V_62 >= V_4 )
return;
F_28 () ;
V_2 = F_29 ( V_6 [ V_62 ] ) ;
if ( V_2 && V_2 -> V_60 )
V_2 -> V_60 ( V_10 , V_53 ) ;
F_30 () ;
}
int F_40 ( struct V_47 * V_68 )
{
struct V_47 * * V_2 = (struct V_47 * * )
& V_48 [ V_68 -> V_69 ] ;
return ( F_2 ( V_2 , NULL , V_68 ) == NULL ) ? 0 : - V_7 ;
}
int F_41 ( struct V_47 * V_70 )
{
struct V_47 * * V_2 = (struct V_47 * * )
& V_48 [ V_70 -> V_69 ] ;
int V_8 ;
V_8 = ( F_2 ( V_2 , V_70 , NULL ) == V_70 ) ? 0 : - V_5 ;
if ( V_8 )
return V_8 ;
F_42 () ;
return 0 ;
}
static int T_4 F_43 ( void )
{
F_44 ( L_1 ) ;
if ( F_45 ( & V_71 , V_58 ) < 0 ) {
F_46 ( L_2 ) ;
goto V_72;
}
if ( F_1 ( & V_73 , V_74 ) < 0 ) {
F_44 ( L_3 , V_75 ) ;
goto V_76;
}
return 0 ;
V_76:
F_47 ( & V_71 , V_58 ) ;
V_72:
return - V_77 ;
}
static void T_5 F_48 ( void )
{
F_3 ( & V_73 , V_74 ) ;
F_47 ( & V_71 , V_58 ) ;
}
