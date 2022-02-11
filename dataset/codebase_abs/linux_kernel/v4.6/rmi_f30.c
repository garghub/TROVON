static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int error = 0 ;
error = F_2 ( V_6 , V_2 -> V_7 . V_8 ,
V_4 -> V_9 , V_4 -> V_10 ) ;
if ( error ) {
F_3 ( & V_6 -> V_11 , L_1 ,
V_12 , V_2 -> V_7 . V_8 , error ) ;
return error ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long * V_13 )
{
struct V_3 * V_4 = F_5 ( & V_2 -> V_11 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_14 ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 ;
int V_18 ;
if ( ! V_4 -> V_19 )
return 0 ;
if ( V_6 -> V_20 -> V_21 ) {
memcpy ( V_4 -> V_22 , V_6 -> V_20 -> V_21 ,
V_4 -> V_23 ) ;
V_6 -> V_20 -> V_21 += V_4 -> V_23 ;
V_6 -> V_20 -> V_24 -= V_4 -> V_23 ;
} else {
V_14 = F_2 ( V_6 , V_2 -> V_7 . V_25 ,
V_4 -> V_22 , V_4 -> V_23 ) ;
if ( V_14 ) {
F_3 ( & V_2 -> V_11 , L_2 ,
V_12 ) ;
return V_14 ;
}
}
for ( V_18 = 0 ; V_18 < V_4 -> V_23 ; ++ V_18 ) {
for ( V_17 = 0 ; V_15 < V_4 -> V_26 && V_17 < 8 ; ++ V_17 ,
++ V_15 ) {
if ( V_4 -> V_27 [ V_15 ] != 0 ) {
V_16 = ( ( ( V_4 -> V_22 [ V_18 ] >> V_17 ) & 0x01 )
== 0 ) ;
F_6 ( V_28 , & V_2 -> V_11 ,
L_3 ,
V_12 ,
V_4 -> V_27 [ V_15 ] , V_16 ) ;
F_7 ( V_4 -> V_19 ,
V_4 -> V_27 [ V_15 ] ,
V_16 ) ;
}
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_29 * V_30 = F_5 ( & V_6 -> V_11 ) ;
struct V_3 * V_4 = F_5 ( & V_2 -> V_11 ) ;
struct V_31 * V_31 ;
int V_32 = 0 ;
V_31 = V_30 -> V_19 ;
if ( ! V_31 ) {
F_9 ( & V_2 -> V_11 , L_4 ) ;
return - V_33 ;
}
V_4 -> V_19 = V_31 ;
F_10 ( V_34 , V_31 -> V_35 ) ;
V_31 -> V_36 = V_4 -> V_27 ;
V_31 -> V_37 = sizeof( V_38 ) ;
V_31 -> V_39 = V_4 -> V_26 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_26 ; V_17 ++ ) {
if ( V_4 -> V_27 [ V_17 ] != 0 ) {
F_11 ( V_31 , V_34 ,
V_4 -> V_27 [ V_17 ] ) ;
V_32 ++ ;
}
}
if ( V_32 == 1 )
F_12 ( V_40 , V_31 -> V_41 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( & V_2 -> V_11 ) ;
struct V_42 * V_43 = V_2 -> V_6 -> V_44 ;
const struct V_45 * V_46 =
F_14 ( V_2 -> V_6 ) ;
int error ;
if ( V_46 -> V_3 && V_46 -> V_3 -> V_47 ) {
V_43 -> V_48 ( V_2 -> V_6 , V_2 -> V_49 ) ;
} else {
error = F_15 ( V_2 -> V_6 , V_2 -> V_7 . V_8 ,
V_4 -> V_9 , V_4 -> V_10 ) ;
if ( error ) {
F_3 ( & V_2 -> V_6 -> V_11 ,
L_5 ,
V_12 , V_2 -> V_7 . V_8 , error ) ;
return error ;
}
V_43 -> V_50 ( V_2 -> V_6 , V_2 -> V_49 ) ;
}
return 0 ;
}
static inline void F_16 ( struct V_51 * V_52 ,
int * V_53 , int V_54 , T_1 * * V_55 )
{
V_52 -> V_56 = * V_53 ;
V_52 -> V_57 = V_54 ;
V_52 -> V_58 = * V_55 ;
* V_53 += V_54 ;
* V_55 += V_54 ;
}
static inline bool F_17 ( int V_59 ,
struct V_51 * V_52 )
{
int V_60 = V_59 >> 3 ;
int V_61 = V_59 & 0x07 ;
return ! ( V_52 [ 2 ] . V_58 [ V_60 ] & F_18 ( V_61 ) ) &&
( V_52 [ 3 ] . V_58 [ V_60 ] & F_18 ( V_61 ) ) ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_45 * V_46 ;
int V_14 = 0 ;
int V_62 ;
int V_17 ;
int V_59 ;
T_1 V_63 [ V_64 ] ;
T_1 * V_65 ;
T_1 * V_66 ;
V_4 = F_20 ( & V_2 -> V_11 , sizeof( struct V_3 ) ,
V_67 ) ;
if ( ! V_4 )
return - V_68 ;
F_21 ( & V_2 -> V_11 , V_4 ) ;
V_14 = F_2 ( V_2 -> V_6 , V_2 -> V_7 . V_69 , V_63 ,
V_64 ) ;
if ( V_14 ) {
F_3 ( & V_2 -> V_11 , L_6 ) ;
return V_14 ;
}
V_4 -> V_70 = V_63 [ 0 ] & V_71 ;
V_4 -> V_72 = V_63 [ 0 ] & V_73 ;
V_4 -> V_74 = V_63 [ 0 ] & V_75 ;
V_4 -> V_76 = V_63 [ 0 ] & V_77 ;
V_4 -> V_78 = V_63 [ 0 ] & V_79 ;
V_4 -> V_80 = V_63 [ 0 ] & V_81 ;
V_4 -> V_82 = V_63 [ 0 ] & V_83 ;
V_4 -> V_26 = V_63 [ 1 ] & V_84 ;
V_4 -> V_23 = ( V_4 -> V_26 + 7 ) >> 3 ;
V_62 = V_2 -> V_7 . V_8 ;
V_65 = V_4 -> V_9 ;
if ( V_4 -> V_76 && V_4 -> V_74 )
F_16 ( & V_4 -> V_52 [ 0 ] , & V_62 ,
V_4 -> V_23 , & V_65 ) ;
F_16 ( & V_4 -> V_52 [ 1 ] , & V_62 , sizeof( T_1 ) ,
& V_65 ) ;
if ( V_4 -> V_76 ) {
F_16 ( & V_4 -> V_52 [ 2 ] , & V_62 ,
V_4 -> V_23 , & V_65 ) ;
F_16 ( & V_4 -> V_52 [ 3 ] , & V_62 ,
V_4 -> V_23 , & V_65 ) ;
}
if ( V_4 -> V_74 ) {
int V_85 ;
F_16 ( & V_4 -> V_52 [ 4 ] , & V_62 ,
V_4 -> V_23 , & V_65 ) ;
if ( V_4 -> V_70 )
V_85 = 6 ;
else
V_85 = 2 ;
F_16 ( & V_4 -> V_52 [ 5 ] , & V_62 ,
V_85 , & V_65 ) ;
}
if ( V_4 -> V_74 || V_4 -> V_80 ) {
F_16 ( & V_4 -> V_52 [ 6 ] , & V_62 ,
V_4 -> V_26 , & V_65 ) ;
}
if ( V_4 -> V_72 ) {
F_16 ( & V_4 -> V_52 [ 7 ] , & V_62 ,
V_4 -> V_26 , & V_65 ) ;
}
if ( V_4 -> V_78 ) {
F_16 ( & V_4 -> V_52 [ 8 ] , & V_62 ,
V_4 -> V_23 , & V_65 ) ;
F_16 ( & V_4 -> V_52 [ 9 ] , & V_62 ,
sizeof( T_1 ) , & V_65 ) ;
}
if ( V_4 -> V_82 )
F_16 ( & V_4 -> V_52 [ 10 ] , & V_62 ,
sizeof( T_1 ) , & V_65 ) ;
V_4 -> V_10 = V_65 - V_4 -> V_9
? : V_86 ;
V_14 = F_1 ( V_2 , V_4 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_2 -> V_11 ,
L_7 ) ;
return V_14 ;
}
V_66 = F_20 ( & V_2 -> V_11 ,
( V_4 -> V_26 * ( sizeof( V_38 ) ) ) ,
V_67 ) ;
if ( ! V_66 ) {
F_3 ( & V_2 -> V_11 , L_8 ) ;
return - V_68 ;
}
V_4 -> V_27 = ( V_38 * ) V_66 ;
V_46 = F_14 ( V_6 ) ;
if ( V_46 && V_4 -> V_76 ) {
V_59 = V_87 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_26 ; V_17 ++ ) {
if ( F_17 ( V_17 , V_4 -> V_52 ) ) {
V_4 -> V_27 [ V_17 ] = V_59 ++ ;
if ( V_46 -> V_3 &&
V_46 -> V_3 -> V_88 )
break;
}
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_89 ;
const struct V_45 * V_46 =
F_14 ( V_2 -> V_6 ) ;
if ( V_46 -> V_3 && V_46 -> V_3 -> V_47 )
return 0 ;
V_89 = F_19 ( V_2 ) ;
if ( V_89 < 0 )
goto V_90;
V_89 = F_8 ( V_2 ) ;
if ( V_89 < 0 )
goto V_90;
return 0 ;
V_90:
return V_89 ;
}
