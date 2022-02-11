static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
V_2 -> V_4 . V_5 = 's' ;
V_2 -> V_4 . V_6 = V_3 * 8 ;
V_2 -> V_4 . V_7 = sizeof( V_8 ) * 8 ;
V_2 -> V_4 . V_9 = 4 ;
}
static int F_2 ( struct V_10 * V_11 ,
struct V_1 const * V_2 ,
int V_3 , int * V_12 , int * V_13 ,
long V_14 )
{
struct V_15 * V_16 = F_3 ( V_11 ) ;
int V_17 ;
int V_18 ;
V_12 [ 0 ] = 0 ;
V_12 [ 1 ] = 0 ;
switch ( V_14 ) {
case V_19 :
if ( V_3 >= 4 ) {
for ( V_18 = 0 ; V_18 < 4 ; ++ V_18 )
V_12 [ V_18 ] = V_16 -> V_20 [ V_18 ] ;
V_17 = V_21 ;
* V_13 = 4 ;
} else
V_17 = - V_22 ;
break;
case V_23 :
V_12 [ 0 ] = V_16 -> V_24 ;
V_12 [ 1 ] = V_16 -> V_25 ;
return V_16 -> V_26 ;
case V_27 :
* V_12 = V_16 -> V_28 ;
return V_29 ;
case V_30 :
V_17 = F_4 (
& V_16 -> V_31 , & V_12 [ 0 ] , & V_12 [ 1 ] ) ;
break;
case V_32 :
V_17 = F_5 (
& V_16 -> V_31 , & V_12 [ 0 ] , & V_12 [ 1 ] ) ;
break;
default:
V_17 = - V_22 ;
break;
}
return V_17 ;
}
static int F_6 ( struct V_10 * V_11 ,
struct V_1 const * V_2 ,
int V_33 ,
int V_34 ,
long V_14 )
{
struct V_15 * V_16 = F_3 ( V_11 ) ;
int V_35 ;
switch ( V_14 ) {
case V_30 :
V_35 = F_7 (
& V_16 -> V_31 , V_33 , V_34 ) ;
break;
case V_32 :
V_35 = F_8 (
& V_16 -> V_31 , V_33 , V_34 ) ;
break;
default:
V_35 = - V_22 ;
}
return V_35 ;
}
static void F_9 ( struct V_10 * V_11 , T_1 * V_36 , int V_37 )
{
F_10 ( & V_11 -> V_38 , L_1 ) ;
F_11 ( V_11 , ( T_1 * ) V_36 ) ;
F_10 ( & V_11 -> V_38 , L_2 ) ;
}
static int F_12 ( struct V_39 * V_40 ,
unsigned V_41 ,
void * V_42 )
{
struct V_10 * V_11 = F_13 ( V_42 ) ;
struct V_15 * V_16 = F_3 ( V_11 ) ;
F_10 ( & V_11 -> V_38 , L_3 ) ;
if ( F_14 ( & V_16 -> V_31 . V_43 ) )
F_9 ( V_11 ,
( T_1 * ) V_16 -> V_20 ,
sizeof( V_16 -> V_20 ) ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 ,
unsigned V_41 ,
T_2 V_44 , char * V_45 ,
void * V_42 )
{
struct V_10 * V_11 = F_13 ( V_42 ) ;
struct V_15 * V_16 = F_3 ( V_11 ) ;
if ( V_41 == V_46 ) {
memcpy ( V_16 -> V_20 , V_45 ,
sizeof( V_16 -> V_20 ) ) ;
F_10 ( & V_11 -> V_38 , L_4 , V_44 ,
sizeof( V_16 -> V_20 ) ) ;
}
return 0 ;
}
static int F_16 ( struct V_47 * V_48 ,
struct V_39 * V_40 ,
struct V_1 * V_49 ,
unsigned V_41 ,
struct V_15 * V_50 )
{
int V_35 ;
V_35 = F_17 ( V_40 ,
V_51 ,
V_41 ,
V_46 ,
& V_50 -> V_52 ) ;
if ( V_35 )
return V_35 ;
F_1 ( & V_49 [ 0 ] ,
V_50 -> V_52 . V_3 / 4 ) ;
F_10 ( & V_48 -> V_38 , L_5 , V_50 -> V_52 . V_53 ,
V_50 -> V_52 . V_54 ) ;
F_10 ( & V_48 -> V_38 , L_6 ,
V_50 -> V_52 . V_3 ) ;
V_50 -> V_26 = F_18 (
V_40 -> V_55 ,
& V_50 -> V_52 ,
& V_50 -> V_24 , & V_50 -> V_25 ) ;
if ( V_50 -> V_31 . V_56 . V_53 < 0 ) {
F_17 ( V_40 ,
V_57 , V_41 ,
V_58 |
V_59 ,
& V_50 -> V_31 . V_56 ) ;
F_10 ( & V_48 -> V_38 , L_7 ,
V_50 -> V_31 . V_56 . V_53 ,
V_50 -> V_31 . V_56 . V_54 ) ;
}
return 0 ;
}
static int F_19 ( struct V_47 * V_48 )
{
int V_35 ;
char * V_60 ;
struct V_10 * V_11 ;
struct V_15 * V_16 ;
struct V_39 * V_40 = V_48 -> V_38 . V_61 ;
V_11 = F_20 ( & V_48 -> V_38 ,
sizeof( struct V_15 ) ) ;
if ( V_11 == NULL )
return - V_62 ;
F_21 ( V_48 , V_11 ) ;
V_16 = F_3 ( V_11 ) ;
V_16 -> V_31 . V_40 = V_40 ;
V_16 -> V_31 . V_48 = V_48 ;
switch ( V_40 -> V_55 ) {
case V_63 :
V_60 = L_8 ;
break;
case V_64 :
V_60 = L_9 ;
break;
case V_65 :
V_60 = L_10 ;
break;
default:
return - V_22 ;
}
V_35 = F_22 ( V_40 , V_40 -> V_55 ,
& V_16 -> V_31 ) ;
if ( V_35 ) {
F_23 ( & V_48 -> V_38 , L_11 ) ;
return V_35 ;
}
V_11 -> V_49 = F_24 ( & V_48 -> V_38 , V_66 ,
sizeof( V_66 ) ,
V_67 ) ;
if ( ! V_11 -> V_49 ) {
F_23 ( & V_48 -> V_38 , L_12 ) ;
return - V_62 ;
}
V_35 = F_16 ( V_48 , V_40 ,
(struct V_1 * ) V_11 -> V_49 ,
V_40 -> V_55 , V_16 ) ;
if ( V_35 ) {
F_23 ( & V_48 -> V_38 , L_13 ) ;
return V_35 ;
}
V_11 -> V_68 = F_25 ( V_66 ) ;
V_11 -> V_38 . V_69 = & V_48 -> V_38 ;
V_11 -> V_70 = & V_71 ;
V_11 -> V_60 = V_60 ;
V_11 -> V_72 = V_73 ;
V_35 = F_26 ( V_11 , & V_74 ,
NULL , NULL ) ;
if ( V_35 ) {
F_23 ( & V_48 -> V_38 , L_14 ) ;
return V_35 ;
}
F_27 ( & V_16 -> V_31 . V_43 , 0 ) ;
V_35 = F_28 ( V_11 , V_60 ,
& V_16 -> V_31 ) ;
if ( V_35 ) {
F_23 ( & V_48 -> V_38 , L_15 ) ;
goto V_75;
}
V_35 = F_29 ( V_11 ) ;
if ( V_35 ) {
F_23 ( & V_48 -> V_38 , L_16 ) ;
goto V_76;
}
V_16 -> V_77 . V_78 = F_12 ;
V_16 -> V_77 . V_79 = F_15 ;
V_16 -> V_77 . V_48 = V_48 ;
V_35 = F_30 ( V_40 , V_40 -> V_55 ,
& V_16 -> V_77 ) ;
if ( V_35 ) {
F_23 ( & V_48 -> V_38 , L_17 ) ;
goto V_80;
}
return 0 ;
V_80:
F_31 ( V_11 ) ;
V_76:
F_32 ( & V_16 -> V_31 ) ;
V_75:
F_33 ( V_11 ) ;
return V_35 ;
}
static int F_34 ( struct V_47 * V_48 )
{
struct V_39 * V_40 = V_48 -> V_38 . V_61 ;
struct V_10 * V_11 = F_13 ( V_48 ) ;
struct V_15 * V_16 = F_3 ( V_11 ) ;
F_35 ( V_40 , V_40 -> V_55 ) ;
F_31 ( V_11 ) ;
F_32 ( & V_16 -> V_31 ) ;
F_33 ( V_11 ) ;
return 0 ;
}
