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
struct V_14 * V_15 = F_5 ( & V_6 -> V_11 ) ;
int V_16 ;
int V_17 = 0 ;
int V_18 = 0 ;
int V_19 ;
int V_20 ;
if ( ! V_4 -> V_21 )
return 0 ;
if ( V_15 -> V_22 . V_23 ) {
if ( V_15 -> V_22 . V_24 < V_4 -> V_25 ) {
F_6 ( & V_2 -> V_11 , L_2 ) ;
return 0 ;
}
memcpy ( V_4 -> V_26 , V_15 -> V_22 . V_23 ,
V_4 -> V_25 ) ;
V_15 -> V_22 . V_23 += V_4 -> V_25 ;
V_15 -> V_22 . V_24 -= V_4 -> V_25 ;
} else {
V_16 = F_2 ( V_6 , V_2 -> V_7 . V_27 ,
V_4 -> V_26 , V_4 -> V_25 ) ;
if ( V_16 ) {
F_3 ( & V_2 -> V_11 , L_3 ,
V_12 ) ;
return V_16 ;
}
}
for ( V_20 = 0 ; V_20 < V_4 -> V_25 ; ++ V_20 ) {
for ( V_19 = 0 ; V_17 < V_4 -> V_28 && V_19 < 8 ; ++ V_19 ,
++ V_17 ) {
if ( V_4 -> V_29 [ V_17 ] != 0 ) {
V_18 = ( ( ( V_4 -> V_26 [ V_20 ] >> V_19 ) & 0x01 )
== 0 ) ;
F_7 ( V_30 , & V_2 -> V_11 ,
L_4 ,
V_12 ,
V_4 -> V_29 [ V_17 ] , V_18 ) ;
F_8 ( V_4 -> V_21 ,
V_4 -> V_29 [ V_17 ] ,
V_18 ) ;
}
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_14 * V_31 = F_5 ( & V_6 -> V_11 ) ;
struct V_3 * V_4 = F_5 ( & V_2 -> V_11 ) ;
struct V_32 * V_32 ;
int V_33 = 0 ;
V_32 = V_31 -> V_21 ;
if ( ! V_32 ) {
F_10 ( & V_2 -> V_11 , L_5 ) ;
return - V_34 ;
}
V_4 -> V_21 = V_32 ;
F_11 ( V_35 , V_32 -> V_36 ) ;
V_32 -> V_37 = V_4 -> V_29 ;
V_32 -> V_38 = sizeof( V_39 ) ;
V_32 -> V_40 = V_4 -> V_28 ;
for ( V_19 = 0 ; V_19 < V_4 -> V_28 ; V_19 ++ ) {
if ( V_4 -> V_29 [ V_19 ] != 0 ) {
F_12 ( V_32 , V_35 ,
V_4 -> V_29 [ V_19 ] ) ;
V_33 ++ ;
}
}
if ( V_33 == 1 )
F_13 ( V_41 , V_32 -> V_42 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( & V_2 -> V_11 ) ;
struct V_43 * V_44 = V_2 -> V_6 -> V_45 ;
const struct V_46 * V_47 =
F_15 ( V_2 -> V_6 ) ;
int error ;
if ( V_47 -> V_3 . V_48 ) {
V_44 -> V_49 ( V_2 -> V_6 , V_2 -> V_50 ) ;
} else {
error = F_16 ( V_2 -> V_6 , V_2 -> V_7 . V_8 ,
V_4 -> V_9 , V_4 -> V_10 ) ;
if ( error ) {
F_3 ( & V_2 -> V_6 -> V_11 ,
L_6 ,
V_12 , V_2 -> V_7 . V_8 , error ) ;
return error ;
}
V_44 -> V_51 ( V_2 -> V_6 , V_2 -> V_50 ) ;
}
return 0 ;
}
static inline void F_17 ( struct V_52 * V_53 ,
int * V_54 , int V_55 , T_1 * * V_56 )
{
V_53 -> V_57 = * V_54 ;
V_53 -> V_58 = V_55 ;
V_53 -> V_59 = * V_56 ;
* V_54 += V_55 ;
* V_56 += V_55 ;
}
static inline bool F_18 ( int V_60 ,
struct V_52 * V_53 )
{
int V_61 = V_60 >> 3 ;
int V_62 = V_60 & 0x07 ;
return ! ( V_53 [ 2 ] . V_59 [ V_61 ] & F_19 ( V_62 ) ) &&
( V_53 [ 3 ] . V_59 [ V_61 ] & F_19 ( V_62 ) ) ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_46 * V_47 ;
int V_16 = 0 ;
int V_63 ;
int V_19 ;
int V_60 ;
T_1 V_64 [ V_65 ] ;
T_1 * V_66 ;
T_1 * V_67 ;
V_4 = F_21 ( & V_2 -> V_11 , sizeof( struct V_3 ) ,
V_68 ) ;
if ( ! V_4 )
return - V_69 ;
F_22 ( & V_2 -> V_11 , V_4 ) ;
V_16 = F_2 ( V_2 -> V_6 , V_2 -> V_7 . V_70 , V_64 ,
V_65 ) ;
if ( V_16 ) {
F_3 ( & V_2 -> V_11 , L_7 ) ;
return V_16 ;
}
V_4 -> V_71 = V_64 [ 0 ] & V_72 ;
V_4 -> V_73 = V_64 [ 0 ] & V_74 ;
V_4 -> V_75 = V_64 [ 0 ] & V_76 ;
V_4 -> V_77 = V_64 [ 0 ] & V_78 ;
V_4 -> V_79 = V_64 [ 0 ] & V_80 ;
V_4 -> V_81 = V_64 [ 0 ] & V_82 ;
V_4 -> V_83 = V_64 [ 0 ] & V_84 ;
V_4 -> V_28 = V_64 [ 1 ] & V_85 ;
V_4 -> V_25 = ( V_4 -> V_28 + 7 ) >> 3 ;
V_63 = V_2 -> V_7 . V_8 ;
V_66 = V_4 -> V_9 ;
if ( V_4 -> V_77 && V_4 -> V_75 )
F_17 ( & V_4 -> V_53 [ 0 ] , & V_63 ,
V_4 -> V_25 , & V_66 ) ;
F_17 ( & V_4 -> V_53 [ 1 ] , & V_63 , sizeof( T_1 ) ,
& V_66 ) ;
if ( V_4 -> V_77 ) {
F_17 ( & V_4 -> V_53 [ 2 ] , & V_63 ,
V_4 -> V_25 , & V_66 ) ;
F_17 ( & V_4 -> V_53 [ 3 ] , & V_63 ,
V_4 -> V_25 , & V_66 ) ;
}
if ( V_4 -> V_75 ) {
int V_86 ;
F_17 ( & V_4 -> V_53 [ 4 ] , & V_63 ,
V_4 -> V_25 , & V_66 ) ;
if ( V_4 -> V_71 )
V_86 = 6 ;
else
V_86 = 2 ;
F_17 ( & V_4 -> V_53 [ 5 ] , & V_63 ,
V_86 , & V_66 ) ;
}
if ( V_4 -> V_75 || V_4 -> V_81 ) {
F_17 ( & V_4 -> V_53 [ 6 ] , & V_63 ,
V_4 -> V_28 , & V_66 ) ;
}
if ( V_4 -> V_73 ) {
F_17 ( & V_4 -> V_53 [ 7 ] , & V_63 ,
V_4 -> V_28 , & V_66 ) ;
}
if ( V_4 -> V_79 ) {
F_17 ( & V_4 -> V_53 [ 8 ] , & V_63 ,
V_4 -> V_25 , & V_66 ) ;
F_17 ( & V_4 -> V_53 [ 9 ] , & V_63 ,
sizeof( T_1 ) , & V_66 ) ;
}
if ( V_4 -> V_83 )
F_17 ( & V_4 -> V_53 [ 10 ] , & V_63 ,
sizeof( T_1 ) , & V_66 ) ;
V_4 -> V_10 = V_66 - V_4 -> V_9
? : V_87 ;
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_16 < 0 ) {
F_3 ( & V_2 -> V_11 ,
L_8 ) ;
return V_16 ;
}
V_67 = F_21 ( & V_2 -> V_11 ,
( V_4 -> V_28 * ( sizeof( V_39 ) ) ) ,
V_68 ) ;
if ( ! V_67 ) {
F_3 ( & V_2 -> V_11 , L_9 ) ;
return - V_69 ;
}
V_4 -> V_29 = ( V_39 * ) V_67 ;
V_47 = F_15 ( V_6 ) ;
if ( V_4 -> V_77 ) {
V_60 = V_88 ;
for ( V_19 = 0 ; V_19 < V_4 -> V_28 ; V_19 ++ ) {
if ( F_18 ( V_19 , V_4 -> V_53 ) ) {
V_4 -> V_29 [ V_19 ] = V_60 ++ ;
if ( V_47 -> V_3 . V_89 )
break;
}
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_90 ;
const struct V_46 * V_47 =
F_15 ( V_2 -> V_6 ) ;
if ( V_47 -> V_3 . V_48 )
return 0 ;
V_90 = F_20 ( V_2 ) ;
if ( V_90 < 0 )
goto V_91;
V_90 = F_9 ( V_2 ) ;
if ( V_90 < 0 )
goto V_91;
return 0 ;
V_91:
return V_90 ;
}
