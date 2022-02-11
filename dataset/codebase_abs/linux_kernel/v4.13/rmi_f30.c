static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int error ;
error = F_2 ( V_2 -> V_5 , V_2 -> V_6 . V_7 ,
V_4 -> V_8 , V_4 -> V_9 ) ;
if ( error ) {
F_3 ( & V_2 -> V_10 ,
L_1 ,
V_11 , V_2 -> V_6 . V_7 , error ) ;
return error ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_12 )
{
unsigned int V_13 = V_12 >> 3 ;
unsigned int V_14 = V_12 & 0x07 ;
T_1 V_15 = V_4 -> V_16 [ V_12 ] ;
bool V_17 = ! ( V_4 -> V_18 [ V_13 ] & F_5 ( V_14 ) ) ;
if ( V_4 -> V_19 &&
V_12 >= V_20 &&
V_12 <= V_21 ) {
F_6 ( V_4 -> V_22 , V_15 , V_17 ) ;
} else {
F_7 ( V_23 , & V_2 -> V_10 ,
L_2 ,
V_11 , V_15 , V_17 ) ;
F_8 ( V_4 -> V_24 , V_15 , V_17 ) ;
}
}
static int F_9 ( struct V_1 * V_2 , unsigned long * V_25 )
{
struct V_3 * V_4 = F_10 ( & V_2 -> V_10 ) ;
struct V_26 * V_27 = F_10 ( & V_2 -> V_5 -> V_10 ) ;
int error ;
int V_28 ;
if ( V_27 -> V_29 . V_30 ) {
if ( V_27 -> V_29 . V_31 < V_4 -> V_32 ) {
F_11 ( & V_2 -> V_10 ,
L_3 ) ;
return 0 ;
}
memcpy ( V_4 -> V_18 , V_27 -> V_29 . V_30 ,
V_4 -> V_32 ) ;
V_27 -> V_29 . V_30 += V_4 -> V_32 ;
V_27 -> V_29 . V_31 -= V_4 -> V_32 ;
} else {
error = F_2 ( V_2 -> V_5 , V_2 -> V_6 . V_33 ,
V_4 -> V_18 , V_4 -> V_32 ) ;
if ( error ) {
F_3 ( & V_2 -> V_10 ,
L_4 ,
V_11 , error ) ;
return error ;
}
}
if ( V_4 -> V_34 ) {
for ( V_28 = 0 ; V_28 < V_4 -> V_35 ; V_28 ++ )
if ( V_4 -> V_16 [ V_28 ] != V_36 )
F_4 ( V_2 , V_4 , V_28 ) ;
if ( V_4 -> V_19 )
F_12 ( V_4 -> V_22 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_10 ( & V_2 -> V_10 ) ;
struct V_37 * V_38 = V_2 -> V_5 -> V_39 ;
const struct V_40 * V_41 =
F_14 ( V_2 -> V_5 ) ;
int error ;
if ( ! V_4 )
return 0 ;
if ( V_41 -> V_3 . V_19 ) {
V_4 -> V_22 = F_15 ( V_2 -> V_5 , 0x03 ) ;
V_4 -> V_19 = V_4 -> V_22 != NULL ;
}
if ( V_41 -> V_3 . V_42 ) {
V_38 -> V_43 ( V_2 -> V_5 , V_2 -> V_44 ) ;
} else {
error = F_16 ( V_2 -> V_5 , V_2 -> V_6 . V_7 ,
V_4 -> V_8 , V_4 -> V_9 ) ;
if ( error ) {
F_3 ( & V_2 -> V_10 ,
L_5 ,
V_11 , V_2 -> V_6 . V_7 , error ) ;
return error ;
}
V_38 -> V_45 ( V_2 -> V_5 , V_2 -> V_44 ) ;
}
return 0 ;
}
static void F_17 ( struct V_46 * V_47 ,
int * V_48 , int V_49 , T_2 * * V_50 )
{
V_47 -> V_51 = * V_48 ;
V_47 -> V_52 = V_49 ;
V_47 -> V_53 = * V_50 ;
* V_48 += V_49 ;
* V_50 += V_49 ;
}
static bool F_18 ( int V_12 , struct V_46 * V_47 )
{
int V_54 = V_12 >> 3 ;
int V_55 = V_12 & 0x07 ;
return ! ( V_47 [ 2 ] . V_53 [ V_54 ] & F_5 ( V_55 ) ) &&
( V_47 [ 3 ] . V_53 [ V_54 ] & F_5 ( V_55 ) ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_40 * V_41 =
F_14 ( V_2 -> V_5 ) ;
struct V_56 * V_24 = V_4 -> V_24 ;
unsigned int V_12 = V_57 ;
unsigned int V_58 = V_57 ;
bool V_59 = false ;
int V_28 ;
V_4 -> V_16 = F_20 ( & V_2 -> V_10 ,
V_4 -> V_35 ,
sizeof( V_4 -> V_16 [ 0 ] ) ,
V_60 ) ;
if ( ! V_4 -> V_16 ) {
F_3 ( & V_2 -> V_10 , L_6 ) ;
return - V_61 ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_35 ; V_28 ++ ) {
if ( ! F_18 ( V_28 , V_4 -> V_47 ) )
continue;
if ( V_41 -> V_3 . V_19 &&
V_28 >= V_20 && V_28 < V_21 ) {
V_4 -> V_16 [ V_28 ] = V_58 ++ ;
} else if ( ! V_41 -> V_3 . V_62 || ! V_59 ) {
V_4 -> V_16 [ V_28 ] = V_12 ;
F_21 ( V_24 , V_63 , V_12 ++ ) ;
V_59 = true ;
}
}
V_24 -> V_64 = V_4 -> V_16 ;
V_24 -> V_65 = sizeof( V_4 -> V_16 [ 0 ] ) ;
V_24 -> V_66 = V_4 -> V_35 ;
if ( V_41 -> V_3 . V_62 || ( V_12 - V_57 == 1 ) )
F_22 ( V_67 , V_24 -> V_68 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 * V_69 = V_4 -> V_8 ;
int V_70 = V_2 -> V_6 . V_7 ;
T_2 V_71 [ V_72 ] ;
int error ;
error = F_2 ( V_2 -> V_5 , V_2 -> V_6 . V_73 ,
V_71 , V_72 ) ;
if ( error ) {
F_3 ( & V_2 -> V_10 , L_7 ) ;
return error ;
}
V_4 -> V_74 = V_71 [ 0 ] & V_75 ;
V_4 -> V_76 = V_71 [ 0 ] & V_77 ;
V_4 -> V_78 = V_71 [ 0 ] & V_79 ;
V_4 -> V_34 = V_71 [ 0 ] & V_80 ;
V_4 -> V_81 = V_71 [ 0 ] & V_82 ;
V_4 -> V_83 = V_71 [ 0 ] & V_84 ;
V_4 -> V_85 = V_71 [ 0 ] & V_86 ;
V_4 -> V_35 = V_71 [ 1 ] & V_87 ;
V_4 -> V_32 = F_24 ( V_4 -> V_35 , 8 ) ;
if ( V_4 -> V_34 && V_4 -> V_78 )
F_17 ( & V_4 -> V_47 [ 0 ] , & V_70 ,
V_4 -> V_32 , & V_69 ) ;
F_17 ( & V_4 -> V_47 [ 1 ] , & V_70 ,
sizeof( T_2 ) , & V_69 ) ;
if ( V_4 -> V_34 ) {
F_17 ( & V_4 -> V_47 [ 2 ] , & V_70 ,
V_4 -> V_32 , & V_69 ) ;
F_17 ( & V_4 -> V_47 [ 3 ] , & V_70 ,
V_4 -> V_32 , & V_69 ) ;
}
if ( V_4 -> V_78 ) {
F_17 ( & V_4 -> V_47 [ 4 ] , & V_70 ,
V_4 -> V_32 , & V_69 ) ;
F_17 ( & V_4 -> V_47 [ 5 ] , & V_70 ,
V_4 -> V_74 ? 6 : 2 ,
& V_69 ) ;
}
if ( V_4 -> V_78 || V_4 -> V_83 ) {
F_17 ( & V_4 -> V_47 [ 6 ] , & V_70 ,
V_4 -> V_35 , & V_69 ) ;
}
if ( V_4 -> V_76 ) {
F_17 ( & V_4 -> V_47 [ 7 ] , & V_70 ,
V_4 -> V_35 , & V_69 ) ;
}
if ( V_4 -> V_81 ) {
F_17 ( & V_4 -> V_47 [ 8 ] , & V_70 ,
V_4 -> V_32 , & V_69 ) ;
F_17 ( & V_4 -> V_47 [ 9 ] , & V_70 ,
sizeof( T_2 ) , & V_69 ) ;
}
if ( V_4 -> V_85 )
F_17 ( & V_4 -> V_47 [ 10 ] , & V_70 ,
sizeof( T_2 ) , & V_69 ) ;
V_4 -> V_9 = V_69 -
V_4 -> V_8 ? : V_88 ;
error = F_1 ( V_2 , V_4 ) ;
if ( error ) {
F_3 ( & V_2 -> V_10 ,
L_8 ,
error ) ;
return error ;
}
if ( V_4 -> V_34 ) {
error = F_19 ( V_2 , V_4 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_89 * V_5 = V_2 -> V_5 ;
const struct V_40 * V_41 =
F_14 ( V_5 ) ;
struct V_26 * V_90 = F_10 ( & V_5 -> V_10 ) ;
struct V_3 * V_4 ;
int error ;
if ( V_41 -> V_3 . V_42 )
return 0 ;
if ( ! V_90 -> V_24 ) {
F_26 ( & V_2 -> V_10 , L_9 ) ;
return - V_91 ;
}
V_4 = F_27 ( & V_2 -> V_10 , sizeof( * V_4 ) , V_60 ) ;
if ( ! V_4 )
return - V_61 ;
V_4 -> V_24 = V_90 -> V_24 ;
error = F_23 ( V_2 , V_4 ) ;
if ( error )
return error ;
F_28 ( & V_2 -> V_10 , V_4 ) ;
return 0 ;
}
