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
if ( F_13 ( V_10 , & V_12 , & V_33 ) < 0 )
goto V_44;
F_23 () ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_46 * V_2 ;
int V_8 ;
V_2 = F_24 ( V_47 [ V_43 ] ) ;
if ( ! V_2 )
continue;
V_8 = V_2 -> V_48 ( V_10 , & V_12 ) ;
if ( V_8 == V_49 ) {
F_25 () ;
return 0 ;
}
}
F_25 () ;
F_26 ( V_10 , V_50 , V_51 , 0 ) ;
V_44:
F_27 ( V_10 ) ;
return 0 ;
}
static void F_28 ( struct V_9 * V_10 , T_3 V_52 )
{
const int type = F_29 ( V_10 ) -> type ;
const int V_53 = F_29 ( V_10 ) -> V_53 ;
struct V_11 V_12 ;
bool V_33 = false ;
int V_43 ;
if ( F_13 ( V_10 , & V_12 , & V_33 ) ) {
if ( ! V_33 )
return;
}
if ( type == V_50 && V_53 == V_54 ) {
F_30 ( V_10 , F_31 ( V_10 -> V_55 ) , V_52 ,
V_10 -> V_55 -> V_56 , 0 , V_57 , 0 ) ;
return;
}
if ( type == V_58 ) {
F_32 ( V_10 , F_31 ( V_10 -> V_55 ) , V_10 -> V_55 -> V_56 , 0 ,
V_57 , 0 ) ;
return;
}
F_23 () ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_46 * V_2 ;
V_2 = F_24 ( V_47 [ V_43 ] ) ;
if ( ! V_2 )
continue;
if ( V_2 -> V_59 ( V_10 , V_52 , & V_12 ) == V_49 )
goto V_60;
}
V_60:
F_25 () ;
}
static int F_33 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 ;
T_1 V_61 ;
int V_8 ;
if ( ! F_16 ( V_10 , 12 ) )
goto V_44;
V_61 = V_10 -> V_16 [ 1 ] & 0x7f ;
if ( V_61 >= V_4 )
goto V_44;
F_23 () ;
V_2 = F_24 ( V_6 [ V_61 ] ) ;
if ( ! V_2 || ! V_2 -> V_48 )
goto V_62;
V_8 = V_2 -> V_48 ( V_10 ) ;
F_25 () ;
return V_8 ;
V_62:
F_25 () ;
V_44:
F_27 ( V_10 ) ;
return V_63 ;
}
static void F_34 ( struct V_9 * V_10 , T_3 V_52 )
{
const struct V_1 * V_2 ;
const struct V_64 * V_65 = ( const struct V_64 * ) V_10 -> V_16 ;
T_1 V_61 = V_10 -> V_16 [ ( V_65 -> V_66 << 2 ) + 1 ] & 0x7f ;
if ( V_61 >= V_4 )
return;
F_23 () ;
V_2 = F_24 ( V_6 [ V_61 ] ) ;
if ( V_2 && V_2 -> V_59 )
V_2 -> V_59 ( V_10 , V_52 ) ;
F_25 () ;
}
int F_35 ( struct V_46 * V_67 )
{
struct V_46 * * V_2 = (struct V_46 * * )
& V_47 [ V_67 -> V_68 ] ;
return ( F_2 ( V_2 , NULL , V_67 ) == NULL ) ? 0 : - V_7 ;
}
int F_36 ( struct V_46 * V_69 )
{
struct V_46 * * V_2 = (struct V_46 * * )
& V_47 [ V_69 -> V_68 ] ;
int V_8 ;
V_8 = ( F_2 ( V_2 , V_69 , NULL ) == V_69 ) ? 0 : - V_5 ;
if ( V_8 )
return V_8 ;
F_37 () ;
return 0 ;
}
static int T_4 F_38 ( void )
{
F_39 ( L_1 ) ;
if ( F_40 ( & V_70 , V_57 ) < 0 ) {
F_41 ( L_2 ) ;
goto V_71;
}
if ( F_1 ( & V_72 , V_73 ) < 0 ) {
F_39 ( L_3 , V_74 ) ;
goto V_75;
}
if ( F_42 () ) {
F_41 ( L_4 ) ;
goto V_76;
}
return 0 ;
V_76:
F_3 ( & V_72 , V_73 ) ;
V_75:
F_43 ( & V_70 , V_57 ) ;
V_71:
return - V_77 ;
}
static void T_5 F_44 ( void )
{
F_45 () ;
F_3 ( & V_72 , V_73 ) ;
F_43 ( & V_70 , V_57 ) ;
}
