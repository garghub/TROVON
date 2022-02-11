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
V_17 = F_4 (
& V_16 -> V_24 , & V_12 [ 0 ] , & V_12 [ 1 ] ) ;
break;
case V_25 :
V_17 = F_5 (
& V_16 -> V_24 , & V_12 [ 0 ] , & V_12 [ 1 ] ) ;
break;
default:
V_17 = - V_22 ;
break;
}
return V_17 ;
}
static int F_6 ( struct V_10 * V_11 ,
struct V_1 const * V_2 ,
int V_26 ,
int V_27 ,
long V_14 )
{
struct V_15 * V_16 = F_3 ( V_11 ) ;
int V_28 ;
switch ( V_14 ) {
case V_23 :
V_28 = F_7 (
& V_16 -> V_24 , V_26 , V_27 ) ;
break;
case V_25 :
V_28 = F_8 (
& V_16 -> V_24 , V_26 , V_27 ) ;
break;
default:
V_28 = - V_22 ;
}
return V_28 ;
}
static void F_9 ( struct V_10 * V_11 , T_1 * V_29 , int V_30 )
{
F_10 ( & V_11 -> V_31 , L_1 ) ;
F_11 ( V_11 , ( T_1 * ) V_29 ) ;
F_10 ( & V_11 -> V_31 , L_2 ) ;
}
static int F_12 ( struct V_32 * V_33 ,
unsigned V_34 ,
void * V_35 )
{
struct V_10 * V_11 = F_13 ( V_35 ) ;
struct V_15 * V_16 = F_3 ( V_11 ) ;
F_10 ( & V_11 -> V_31 , L_3 ) ;
if ( F_14 ( & V_16 -> V_24 . V_36 ) )
F_9 ( V_11 ,
( T_1 * ) V_16 -> V_20 ,
sizeof( V_16 -> V_20 ) ) ;
return 0 ;
}
static int F_15 ( struct V_32 * V_33 ,
unsigned V_34 ,
T_2 V_37 , char * V_38 ,
void * V_35 )
{
struct V_10 * V_11 = F_13 ( V_35 ) ;
struct V_15 * V_16 = F_3 ( V_11 ) ;
if ( V_34 == V_39 ) {
memcpy ( V_16 -> V_20 , V_38 ,
sizeof( V_16 -> V_20 ) ) ;
F_10 ( & V_11 -> V_31 , L_4 , V_37 ,
sizeof( V_16 -> V_20 ) ) ;
}
return 0 ;
}
static int F_16 ( struct V_40 * V_41 ,
struct V_32 * V_33 ,
struct V_1 * V_42 ,
unsigned V_34 ,
struct V_15 * V_43 )
{
int V_28 ;
V_28 = F_17 ( V_33 ,
V_44 ,
V_34 ,
V_39 ,
& V_43 -> V_45 ) ;
if ( V_28 )
return V_28 ;
F_1 ( & V_42 [ 0 ] ,
V_43 -> V_45 . V_3 / 4 ) ;
F_10 ( & V_41 -> V_31 , L_5 , V_43 -> V_45 . V_46 ,
V_43 -> V_45 . V_47 ) ;
F_10 ( & V_41 -> V_31 , L_6 ,
V_43 -> V_45 . V_3 ) ;
if ( V_43 -> V_24 . V_48 . V_46 < 0 ) {
F_17 ( V_33 ,
V_49 , V_34 ,
V_50 |
V_51 ,
& V_43 -> V_24 . V_48 ) ;
F_10 ( & V_41 -> V_31 , L_7 ,
V_43 -> V_24 . V_48 . V_46 ,
V_43 -> V_24 . V_48 . V_47 ) ;
}
return 0 ;
}
static int F_18 ( struct V_40 * V_41 )
{
int V_28 ;
static char * V_52 = L_8 ;
struct V_10 * V_11 ;
struct V_15 * V_16 ;
struct V_32 * V_33 = V_41 -> V_31 . V_53 ;
struct V_1 * V_42 ;
V_11 = F_19 ( & V_41 -> V_31 ,
sizeof( struct V_15 ) ) ;
if ( V_11 == NULL )
return - V_54 ;
F_20 ( V_41 , V_11 ) ;
V_16 = F_3 ( V_11 ) ;
V_16 -> V_24 . V_33 = V_33 ;
V_16 -> V_24 . V_41 = V_41 ;
V_28 = F_21 ( V_33 ,
V_55 ,
& V_16 -> V_24 ) ;
if ( V_28 ) {
F_22 ( & V_41 -> V_31 , L_9 ) ;
return V_28 ;
}
V_42 = F_23 ( & V_41 -> V_31 , V_56 ,
sizeof( V_56 ) , V_57 ) ;
if ( ! V_42 ) {
F_22 ( & V_41 -> V_31 , L_10 ) ;
return - V_54 ;
}
V_28 = F_16 ( V_41 , V_33 , V_42 ,
V_55 , V_16 ) ;
if ( V_28 ) {
F_22 ( & V_41 -> V_31 , L_11 ) ;
return V_28 ;
}
V_11 -> V_42 = V_42 ;
V_11 -> V_58 = F_24 ( V_56 ) ;
V_11 -> V_31 . V_59 = & V_41 -> V_31 ;
V_11 -> V_60 = & V_61 ;
V_11 -> V_52 = V_52 ;
V_11 -> V_62 = V_63 ;
V_28 = F_25 ( V_11 , & V_64 ,
NULL , NULL ) ;
if ( V_28 ) {
F_22 ( & V_41 -> V_31 , L_12 ) ;
return V_28 ;
}
F_26 ( & V_16 -> V_24 . V_36 , 0 ) ;
V_28 = F_27 ( V_11 , V_52 ,
& V_16 -> V_24 ) ;
if ( V_28 ) {
F_22 ( & V_41 -> V_31 , L_13 ) ;
goto V_65;
}
V_28 = F_28 ( V_11 ) ;
if ( V_28 ) {
F_22 ( & V_41 -> V_31 , L_14 ) ;
goto V_66;
}
V_16 -> V_67 . V_68 = F_12 ;
V_16 -> V_67 . V_69 = F_15 ;
V_16 -> V_67 . V_41 = V_41 ;
V_28 = F_29 ( V_33 ,
V_55 ,
& V_16 -> V_67 ) ;
if ( V_28 ) {
F_22 ( & V_41 -> V_31 , L_15 ) ;
goto V_70;
}
return 0 ;
V_70:
F_30 ( V_11 ) ;
V_66:
F_31 ( & V_16 -> V_24 ) ;
V_65:
F_32 ( V_11 ) ;
return V_28 ;
}
static int F_33 ( struct V_40 * V_41 )
{
struct V_32 * V_33 = V_41 -> V_31 . V_53 ;
struct V_10 * V_11 = F_13 ( V_41 ) ;
struct V_15 * V_16 = F_3 ( V_11 ) ;
F_34 ( V_33 , V_55 ) ;
F_30 ( V_11 ) ;
F_31 ( & V_16 -> V_24 ) ;
F_32 ( V_11 ) ;
return 0 ;
}
