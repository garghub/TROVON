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
struct V_9 * F_11 ( struct V_9 * V_10 , bool V_29 )
{
int V_30 ;
if ( F_12 ( ! V_10 -> V_31 ) ) {
F_13 ( V_10 ) ;
V_10 -> V_31 = 1 ;
}
if ( F_14 ( V_10 ) ) {
V_30 = F_15 ( V_10 , V_32 ) ;
if ( F_16 ( V_30 ) )
goto error;
F_8 ( V_10 ) -> V_25 |= V_26 ;
return V_10 ;
} else if ( V_10 -> V_33 == V_34 && V_29 ) {
V_30 = F_17 ( V_10 ) ;
if ( F_16 ( V_30 ) )
goto error;
} else if ( V_10 -> V_33 != V_34 )
V_10 -> V_33 = V_35 ;
return V_10 ;
error:
F_18 ( V_10 ) ;
return F_19 ( V_30 ) ;
}
static V_27 F_20 ( struct V_9 * V_10 )
{
V_27 V_36 = 0 ;
switch ( V_10 -> V_33 ) {
case V_37 :
V_36 = F_9 ( V_10 -> V_36 ) ;
if ( ! V_36 )
break;
case V_35 :
V_10 -> V_36 = 0 ;
V_36 = F_21 ( V_10 ) ;
V_10 -> V_33 = V_37 ;
break;
}
return V_36 ;
}
static int F_22 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool * V_38 )
{
unsigned int V_39 = F_23 ( V_10 ) ;
const struct V_14 * V_15 ;
T_2 * V_40 ;
int V_13 ;
if ( F_16 ( ! F_24 ( V_10 , sizeof( struct V_14 ) ) ) )
return - V_5 ;
V_15 = (struct V_14 * ) ( F_25 ( V_10 ) + V_39 ) ;
if ( F_16 ( V_15 -> V_17 & ( V_41 | V_42 ) ) )
return - V_5 ;
V_12 -> V_17 = F_26 ( V_15 -> V_17 ) ;
V_13 = F_27 ( V_12 -> V_17 ) ;
if ( ! F_24 ( V_10 , V_13 ) )
return - V_5 ;
V_15 = (struct V_14 * ) ( F_25 ( V_10 ) + V_39 ) ;
V_12 -> V_2 = V_15 -> V_18 ;
V_40 = ( T_2 * ) ( V_15 + 1 ) ;
if ( V_15 -> V_17 & V_43 ) {
if ( F_20 ( V_10 ) ) {
* V_38 = true ;
return - V_5 ;
}
V_40 ++ ;
}
if ( V_15 -> V_17 & V_44 ) {
V_12 -> V_24 = * V_40 ;
V_40 ++ ;
} else
V_12 -> V_24 = 0 ;
if ( F_16 ( V_15 -> V_17 & V_45 ) ) {
V_12 -> V_23 = * V_40 ;
V_40 ++ ;
} else
V_12 -> V_23 = 0 ;
if ( V_15 -> V_17 == 0 && V_12 -> V_2 == F_28 ( V_46 ) ) {
V_12 -> V_2 = F_28 ( V_47 ) ;
if ( ( * ( T_1 * ) V_40 & 0xF0 ) != 0x40 ) {
V_13 += 4 ;
if ( ! F_24 ( V_10 , V_13 ) )
return - V_5 ;
}
}
return F_29 ( V_10 , V_13 , V_12 -> V_2 ) ;
}
static int F_30 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
int V_48 ;
bool V_38 = false ;
if ( F_22 ( V_10 , & V_12 , & V_38 ) < 0 )
goto V_49;
F_31 () ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
struct V_51 * V_2 ;
int V_8 ;
V_2 = F_32 ( V_52 [ V_48 ] ) ;
if ( ! V_2 )
continue;
V_8 = V_2 -> V_53 ( V_10 , & V_12 ) ;
if ( V_8 == V_54 ) {
F_33 () ;
return 0 ;
}
}
F_33 () ;
F_34 ( V_10 , V_55 , V_56 , 0 ) ;
V_49:
F_18 ( V_10 ) ;
return 0 ;
}
static void F_35 ( struct V_9 * V_10 , T_3 V_57 )
{
const int type = F_36 ( V_10 ) -> type ;
const int V_58 = F_36 ( V_10 ) -> V_58 ;
struct V_11 V_12 ;
bool V_38 = false ;
int V_48 ;
if ( F_22 ( V_10 , & V_12 , & V_38 ) ) {
if ( ! V_38 )
return;
}
if ( type == V_55 && V_58 == V_59 ) {
F_37 ( V_10 , F_38 ( V_10 -> V_60 ) , V_57 ,
V_10 -> V_60 -> V_61 , 0 , V_62 , 0 ) ;
return;
}
if ( type == V_63 ) {
F_39 ( V_10 , F_38 ( V_10 -> V_60 ) , V_10 -> V_60 -> V_61 , 0 ,
V_62 , 0 ) ;
return;
}
F_31 () ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
struct V_51 * V_2 ;
V_2 = F_32 ( V_52 [ V_48 ] ) ;
if ( ! V_2 )
continue;
if ( V_2 -> V_64 ( V_10 , V_57 , & V_12 ) == V_54 )
goto V_65;
}
V_65:
F_33 () ;
}
static int F_40 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 ;
T_1 V_66 ;
int V_8 ;
if ( ! F_24 ( V_10 , 12 ) )
goto V_49;
V_66 = V_10 -> V_16 [ 1 ] & 0x7f ;
if ( V_66 >= V_4 )
goto V_49;
F_31 () ;
V_2 = F_32 ( V_6 [ V_66 ] ) ;
if ( ! V_2 || ! V_2 -> V_53 )
goto V_67;
V_8 = V_2 -> V_53 ( V_10 ) ;
F_33 () ;
return V_8 ;
V_67:
F_33 () ;
V_49:
F_18 ( V_10 ) ;
return V_68 ;
}
static void F_41 ( struct V_9 * V_10 , T_3 V_57 )
{
const struct V_1 * V_2 ;
const struct V_69 * V_70 = ( const struct V_69 * ) V_10 -> V_16 ;
T_1 V_66 = V_10 -> V_16 [ ( V_70 -> V_71 << 2 ) + 1 ] & 0x7f ;
if ( V_66 >= V_4 )
return;
F_31 () ;
V_2 = F_32 ( V_6 [ V_66 ] ) ;
if ( V_2 && V_2 -> V_64 )
V_2 -> V_64 ( V_10 , V_57 ) ;
F_33 () ;
}
int F_42 ( struct V_51 * V_72 )
{
struct V_51 * * V_2 = (struct V_51 * * )
& V_52 [ V_72 -> V_73 ] ;
return ( F_2 ( V_2 , NULL , V_72 ) == NULL ) ? 0 : - V_7 ;
}
int F_43 ( struct V_51 * V_74 )
{
struct V_51 * * V_2 = (struct V_51 * * )
& V_52 [ V_74 -> V_73 ] ;
int V_8 ;
V_8 = ( F_2 ( V_2 , V_74 , NULL ) == V_74 ) ? 0 : - V_5 ;
if ( V_8 )
return V_8 ;
F_44 () ;
return 0 ;
}
static int T_4 F_45 ( void )
{
F_46 ( L_1 ) ;
if ( F_47 ( & V_75 , V_62 ) < 0 ) {
F_48 ( L_2 ) ;
goto V_30;
}
if ( F_1 ( & V_76 , V_77 ) < 0 ) {
F_46 ( L_3 , V_78 ) ;
goto V_79;
}
if ( F_49 () ) {
F_48 ( L_4 ) ;
goto V_80;
}
return 0 ;
V_80:
F_3 ( & V_76 , V_77 ) ;
V_79:
F_50 ( & V_75 , V_62 ) ;
V_30:
return - V_81 ;
}
static void T_5 F_51 ( void )
{
F_52 () ;
F_3 ( & V_76 , V_77 ) ;
F_50 ( & V_75 , V_62 ) ;
}
