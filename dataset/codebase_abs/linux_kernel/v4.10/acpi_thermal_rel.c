static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_2 ( & V_3 ) ;
if ( V_4 ||
( V_5 && ( V_2 -> V_6 & V_7 ) ) ) {
F_3 ( & V_3 ) ;
return - V_8 ;
}
if ( V_2 -> V_6 & V_7 )
V_4 = 1 ;
V_5 ++ ;
F_3 ( & V_3 ) ;
return F_4 ( V_1 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_2 ( & V_3 ) ;
V_5 -- ;
V_4 = 0 ;
F_3 ( & V_3 ) ;
return 0 ;
}
int F_6 ( T_1 V_9 , int * V_10 , struct V_11 * * V_12 ,
bool V_13 )
{
T_2 V_14 ;
int V_15 = 0 ;
int V_16 ;
int V_17 = 0 ;
struct V_11 * V_18 ;
struct V_19 * V_20 ;
union V_21 * V_22 ;
struct V_23 V_24 = { V_25 , NULL } ;
struct V_23 V_26 = { 0 , NULL } ;
struct V_23 V_27 = { sizeof( L_1 ) , L_1 } ;
if ( ! F_7 ( V_9 , L_2 ) )
return - V_28 ;
V_14 = F_8 ( V_9 , L_2 , NULL , & V_24 ) ;
if ( F_9 ( V_14 ) )
return - V_28 ;
V_22 = V_24 . V_29 ;
if ( ! V_22 || ( V_22 -> type != V_30 ) ) {
F_10 ( L_3 ) ;
V_15 = - V_31 ;
goto V_32;
}
* V_10 = V_22 -> V_33 . V_34 ;
V_18 = F_11 ( * V_10 * sizeof( struct V_11 ) , V_35 ) ;
if ( ! V_18 ) {
V_15 = - V_36 ;
goto V_32;
}
for ( V_16 = 0 ; V_16 < * V_10 ; V_16 ++ ) {
struct V_11 * V_11 = & V_18 [ V_16 - V_17 ] ;
V_26 . V_37 = sizeof( struct V_11 ) ;
V_26 . V_29 = V_11 ;
V_14 = F_12 ( & ( V_22 -> V_33 . V_38 [ V_16 ] ) ,
& V_27 , & V_26 ) ;
if ( F_9 ( V_14 ) ) {
V_17 ++ ;
F_13 ( L_4 , V_16 ) ;
continue;
}
if ( ! V_13 )
continue;
V_15 = F_14 ( V_11 -> V_39 , & V_20 ) ;
if ( V_15 )
F_13 ( L_5 ) ;
V_15 = F_14 ( V_11 -> V_40 , & V_20 ) ;
if ( V_15 )
F_13 ( L_6 ) ;
}
V_15 = 0 ;
* V_12 = V_18 ;
* V_10 -= V_17 ;
V_32:
F_15 ( V_24 . V_29 ) ;
return V_15 ;
}
int F_16 ( T_1 V_9 , int * V_41 , struct V_42 * * V_43 ,
bool V_13 )
{
T_2 V_14 ;
int V_15 = 0 ;
int V_16 ;
int V_17 = 0 ;
struct V_42 * V_44 ;
struct V_19 * V_20 ;
union V_21 * V_22 ;
struct V_23 V_24 = { V_25 , NULL } ;
struct V_23 V_26 = { 0 , NULL } ;
struct V_23 V_45 = {
sizeof( L_7 ) , L_7 } ;
if ( ! F_7 ( V_9 , L_8 ) )
return - V_28 ;
V_14 = F_8 ( V_9 , L_8 , NULL , & V_24 ) ;
if ( F_9 ( V_14 ) )
return - V_28 ;
V_22 = V_24 . V_29 ;
if ( ! V_22 || ( V_22 -> type != V_30 ) ) {
F_10 ( L_9 ) ;
V_15 = - V_31 ;
goto V_32;
}
* V_41 = V_22 -> V_33 . V_34 - 1 ;
V_44 = F_11 ( * V_41 * sizeof( struct V_42 ) , V_35 ) ;
if ( ! V_44 ) {
V_15 = - V_36 ;
goto V_32;
}
for ( V_16 = 0 ; V_16 < * V_41 ; V_16 ++ ) {
struct V_42 * V_42 = & V_44 [ V_16 - V_17 ] ;
V_26 . V_37 = sizeof( struct V_42 ) ;
V_26 . V_29 = V_42 ;
V_14 = F_12 ( & ( V_22 -> V_33 . V_38 [ V_16 + 1 ] ) ,
& V_45 , & V_26 ) ;
if ( F_9 ( V_14 ) ) {
F_13 ( L_10 , V_16 ) ;
V_17 ++ ;
continue;
}
if ( ! V_13 )
continue;
if ( V_42 -> V_39 ) {
V_15 = F_14 ( V_42 -> V_39 , & V_20 ) ;
if ( V_15 )
F_13 ( L_5 ) ;
}
if ( V_42 -> V_40 ) {
V_15 = F_14 ( V_42 -> V_40 , & V_20 ) ;
if ( V_15 )
F_13 ( L_5 ) ;
}
}
* V_43 = V_44 ;
* V_41 -= V_17 ;
V_32:
F_15 ( V_24 . V_29 ) ;
return V_15 ;
}
static void F_17 ( T_1 V_9 , char * V_46 )
{
struct V_23 V_24 = { V_25 } ;
if ( F_9 ( F_18 ( V_9 , V_47 , & V_24 ) ) )
F_13 ( L_11 ) ;
else {
memcpy ( V_46 , V_24 . V_29 , V_48 ) ;
F_15 ( V_24 . V_29 ) ;
}
}
static int F_19 ( char T_3 * V_49 )
{
int V_16 ;
int V_50 ;
int V_34 ;
int V_51 ;
struct V_42 * V_44 = NULL ;
union V_52 * V_53 ;
V_50 = F_16 ( V_54 , & V_34 , & V_44 , false ) ;
if ( V_50 )
goto V_55;
V_51 = V_34 * sizeof( union V_52 ) ;
V_53 = F_11 ( V_51 , V_35 ) ;
if ( ! V_53 ) {
V_50 = - V_36 ;
goto V_55;
}
for ( V_16 = 0 ; V_16 < V_34 ; V_16 ++ ) {
F_17 ( V_44 [ V_16 ] . V_39 , V_53 [ V_16 ] . V_56 ) ;
F_17 ( V_44 [ V_16 ] . V_40 , V_53 [ V_16 ] . V_57 ) ;
memcpy ( & V_53 [ V_16 ] . V_58 , & V_44 [ V_16 ] . V_58 ,
sizeof( V_59 ) * ( V_60 - 2 ) ) ;
}
if ( F_20 ( V_49 , V_53 , V_51 ) )
V_50 = - V_31 ;
F_15 ( V_53 ) ;
V_55:
F_15 ( V_44 ) ;
return V_50 ;
}
static int F_21 ( char T_3 * V_49 )
{
int V_16 ;
int V_50 ;
int V_34 ;
int V_61 ;
struct V_11 * V_18 = NULL ;
union V_62 * V_63 ;
V_50 = F_6 ( V_54 , & V_34 , & V_18 , false ) ;
if ( V_50 )
goto V_64;
V_61 = V_34 * sizeof( union V_62 ) ;
V_63 = F_11 ( V_61 , V_35 ) ;
if ( ! V_63 ) {
V_50 = - V_36 ;
goto V_64;
}
for ( V_16 = 0 ; V_16 < V_34 ; V_16 ++ ) {
F_17 ( V_18 [ V_16 ] . V_39 , V_63 [ V_16 ] . V_56 ) ;
F_17 ( V_18 [ V_16 ] . V_40 , V_63 [ V_16 ] . V_57 ) ;
V_63 [ V_16 ] . V_65 = V_18 [ V_16 ] . V_65 ;
V_63 [ V_16 ] . V_66 = V_18 [ V_16 ] . V_66 ;
}
if ( F_20 ( V_49 , V_63 , V_61 ) )
V_50 = - V_31 ;
F_15 ( V_63 ) ;
V_64:
F_15 ( V_18 ) ;
return V_50 ;
}
static long F_22 ( struct V_2 * V_67 , unsigned int V_68 ,
unsigned long V_69 )
{
int V_50 = 0 ;
unsigned long V_37 = 0 ;
int V_34 = 0 ;
char T_3 * V_70 = ( void T_3 * ) V_69 ;
struct V_11 * V_18 = NULL ;
struct V_42 * V_44 = NULL ;
switch ( V_68 ) {
case V_71 :
V_50 = F_6 ( V_54 , & V_34 ,
& V_18 , false ) ;
F_15 ( V_18 ) ;
if ( ! V_50 )
return F_23 ( V_34 , ( unsigned long T_3 * ) V_69 ) ;
return V_50 ;
case V_72 :
V_50 = F_6 ( V_54 , & V_34 ,
& V_18 , false ) ;
F_15 ( V_18 ) ;
V_37 = V_34 * sizeof( union V_62 ) ;
if ( ! V_50 )
return F_23 ( V_37 , ( unsigned long T_3 * ) V_69 ) ;
return V_50 ;
case V_73 :
return F_21 ( V_70 ) ;
case V_74 :
V_50 = F_16 ( V_54 , & V_34 ,
& V_44 , false ) ;
F_15 ( V_44 ) ;
if ( ! V_50 )
return F_23 ( V_34 , ( unsigned long T_3 * ) V_69 ) ;
return V_50 ;
case V_75 :
V_50 = F_16 ( V_54 , & V_34 ,
& V_44 , false ) ;
F_15 ( V_44 ) ;
V_37 = V_34 * sizeof( union V_52 ) ;
if ( ! V_50 )
return F_23 ( V_37 , ( unsigned long T_3 * ) V_69 ) ;
return V_50 ;
case V_76 :
return F_19 ( V_70 ) ;
default:
return - V_77 ;
}
}
int F_24 ( T_1 V_9 )
{
V_54 = V_9 ;
return F_25 ( & V_78 ) ;
}
int F_26 ( T_1 V_9 )
{
F_27 ( & V_78 ) ;
return 0 ;
}
