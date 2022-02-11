static void
F_1 ( short * V_1 , const short * V_2 , unsigned V_3 , unsigned V_4 )
{
memcpy ( V_1 , V_2 , V_3 * sizeof( short ) ) ;
memset ( & V_1 [ V_3 ] , 0 , V_4 * sizeof( short ) ) ;
}
void F_2 (
struct V_5 * V_6 ,
const struct V_7 * V_8 ,
unsigned V_9 )
{
unsigned V_10 = V_8 -> V_11 . V_10 * V_8 -> V_11 . V_12 ;
unsigned V_3 = V_8 -> V_11 . V_13 ;
int V_4 = V_10 - V_3 ;
unsigned V_14 = V_9 / V_15 / sizeof( short ) ;
unsigned V_16 = V_10 * V_15 * sizeof( short ) ;
short * V_1 = ( short * ) V_6 ;
assert ( V_4 >= 0 ) ;
assert ( V_16 <= V_9 ) ;
assert ( V_9 % ( V_15 * V_17 * sizeof( short ) ) == 0 ) ;
F_1 ( & V_1 [ 0 * V_14 ] , V_8 -> V_18 . V_19 , V_3 , V_4 ) ;
F_1 ( & V_1 [ 1 * V_14 ] , V_8 -> V_18 . V_20 , V_3 , V_4 ) ;
F_1 ( & V_1 [ 2 * V_14 ] , V_8 -> V_18 . V_21 , V_3 , V_4 ) ;
F_1 ( & V_1 [ 3 * V_14 ] , V_8 -> V_18 . V_22 , V_3 , V_4 ) ;
}
void F_3 (
struct V_23 * V_6 ,
const struct V_7 * V_8 ,
unsigned V_9 )
{
unsigned V_24 = V_8 -> V_11 . V_24 * V_8 -> V_11 . V_12 ;
unsigned V_25 = V_8 -> V_11 . V_26 ;
int V_4 = V_24 - V_25 ;
unsigned V_14 = V_9 / V_15 / sizeof( short ) ;
unsigned V_16 = V_24 * V_15 * sizeof( short ) ;
short * V_1 = ( short * ) V_6 ;
assert ( V_4 >= 0 ) ;
assert ( V_16 <= V_9 ) ;
assert ( V_9 % ( V_15 * V_17 * sizeof( short ) ) == 0 ) ;
F_1 ( & V_1 [ 0 * V_14 ] , V_8 -> V_27 . V_19 , V_25 , V_4 ) ;
F_1 ( & V_1 [ 1 * V_14 ] , V_8 -> V_27 . V_20 , V_25 , V_4 ) ;
F_1 ( & V_1 [ 2 * V_14 ] , V_8 -> V_27 . V_21 , V_25 , V_4 ) ;
F_1 ( & V_1 [ 3 * V_14 ] , V_8 -> V_27 . V_22 , V_25 , V_4 ) ;
}
void F_4 (
struct V_28 * V_6 ,
const struct V_7 * V_8 ,
unsigned V_9 )
{
( void ) V_6 ;
( void ) V_8 ;
( void ) V_9 ;
}
void F_5 (
struct V_29 * V_6 ,
const struct V_7 * V_8 ,
unsigned V_9 )
{
( void ) V_6 ;
( void ) V_8 ;
( void ) V_9 ;
}
void F_6 (
struct V_30 * V_31 ,
short * V_32 ,
short * V_33 ,
short * V_34 ,
short * V_35 ,
short * V_36 ,
short * V_37 ,
short * V_38 ,
short * V_39 )
{
struct V_40 * V_41 ;
unsigned int V_42 , V_43 ;
unsigned int V_44 , V_45 ;
struct V_46 * V_47 ;
F_7 ( L_1 ) ;
assert ( V_31 != NULL ) ;
assert ( V_32 != NULL ) ;
assert ( V_33 != NULL ) ;
assert ( V_34 != NULL ) ;
assert ( V_35 != NULL ) ;
assert ( V_36 != NULL ) ;
assert ( V_37 != NULL ) ;
assert ( V_38 != NULL ) ;
assert ( V_39 != NULL ) ;
V_41 = V_31 -> V_48 ;
V_47 = F_8 ( V_31 ) ;
if ( ! V_47 )
return;
V_42 = V_47 -> V_49 . V_50 . V_51 . V_3 ;
V_43 = V_47 -> V_49 . V_50 . V_51 . V_25 ;
V_44 = V_47 -> V_49 . V_50 . V_52 . V_3 ;
V_45 = V_47 -> V_49 . V_50 . V_52 . V_25 ;
memcpy ( V_32 , V_41 -> V_53 . V_18 . V_19 , V_42 * sizeof( short ) ) ;
memcpy ( V_33 , V_41 -> V_53 . V_18 . V_20 , V_42 * sizeof( short ) ) ;
memcpy ( V_34 , V_41 -> V_53 . V_18 . V_21 , V_42 * sizeof( short ) ) ;
memcpy ( V_35 , V_41 -> V_53 . V_18 . V_22 , V_42 * sizeof( short ) ) ;
memcpy ( V_36 , V_41 -> V_53 . V_27 . V_19 , V_43 * sizeof( short ) ) ;
memcpy ( V_37 , V_41 -> V_53 . V_27 . V_20 , V_43 * sizeof( short ) ) ;
memcpy ( V_38 , V_41 -> V_53 . V_27 . V_21 , V_43 * sizeof( short ) ) ;
memcpy ( V_39 , V_41 -> V_53 . V_27 . V_22 , V_43 * sizeof( short ) ) ;
F_9 ( L_1 ) ;
}
void F_10 (
struct V_7 * V_53 )
{
V_53 -> V_18 . V_19 = NULL ;
V_53 -> V_18 . V_20 = NULL ;
V_53 -> V_18 . V_21 = NULL ;
V_53 -> V_18 . V_22 = NULL ;
V_53 -> V_27 . V_19 = NULL ;
V_53 -> V_27 . V_20 = NULL ;
V_53 -> V_27 . V_21 = NULL ;
V_53 -> V_27 . V_22 = NULL ;
}
enum V_54
F_11 (
struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_59 * V_60 ;
enum V_54 V_61 = V_62 ;
F_7 ( L_2 , V_56 , V_58 ) ;
assert ( V_56 != NULL ) ;
assert ( V_58 != NULL ) ;
V_60 = F_12 ( V_58 , NULL ) ;
if ( V_60 ) {
F_13 ( V_58 -> V_63 , V_60 -> V_63 , V_58 -> V_9 ) ;
F_14 ( V_56 , V_60 ) ;
F_15 ( V_60 ) ;
} else {
F_16 ( L_3 ) ;
V_61 = V_64 ;
}
F_17 ( V_61 ) ;
return V_61 ;
}
void
F_14 (
struct V_55 * V_56 ,
const struct V_59 * V_58 )
{
unsigned int V_65 , V_66 , V_67 , V_25 ;
unsigned int V_68 = 0 , V_69 = 0 ;
T_1 * V_70 , * V_71 ;
assert ( V_56 != NULL ) ;
assert ( V_56 -> V_72 . V_19 != NULL ) ;
assert ( V_56 -> V_72 . V_20 != NULL ) ;
assert ( V_56 -> V_72 . V_21 != NULL ) ;
assert ( V_56 -> V_72 . V_22 != NULL ) ;
assert ( V_56 -> V_73 . V_19 != NULL ) ;
assert ( V_56 -> V_73 . V_20 != NULL ) ;
assert ( V_56 -> V_73 . V_21 != NULL ) ;
assert ( V_56 -> V_73 . V_22 != NULL ) ;
assert ( V_58 != NULL ) ;
assert ( V_58 -> V_74 != NULL ) ;
assert ( V_58 -> V_75 != NULL ) ;
F_7 ( L_4
L_5
L_6
L_7
L_8 ,
V_56 -> V_72 . V_19 , V_56 -> V_72 . V_20 ,
V_56 -> V_72 . V_21 , V_56 -> V_72 . V_22 ,
V_56 -> V_73 . V_19 , V_56 -> V_73 . V_20 ,
V_56 -> V_73 . V_21 , V_56 -> V_73 . V_22 ,
V_58 -> V_74 , V_58 -> V_75 ) ;
V_65 = V_56 -> V_11 . V_10 * sizeof( * V_70 ) ;
V_66 = F_18 ( V_65 , V_76 ) / sizeof( * V_70 ) ;
V_67 = V_66 * V_56 -> V_11 . V_24 ;
V_70 = V_58 -> V_74 ;
V_71 = V_58 -> V_75 ;
for ( V_25 = 0 ; V_25 < V_56 -> V_11 . V_24 ; V_25 ++ ) {
memcpy ( V_56 -> V_72 . V_19 + V_69 ,
& V_70 [ 0 * V_67 + V_68 ] , V_65 ) ;
memcpy ( V_56 -> V_72 . V_20 + V_69 ,
& V_70 [ 1 * V_67 + V_68 ] , V_65 ) ;
memcpy ( V_56 -> V_72 . V_21 + V_69 ,
& V_70 [ 2 * V_67 + V_68 ] , V_65 ) ;
memcpy ( V_56 -> V_72 . V_22 + V_69 ,
& V_70 [ 3 * V_67 + V_68 ] , V_65 ) ;
memcpy ( V_56 -> V_73 . V_19 + V_69 ,
& V_71 [ 0 * V_67 + V_68 ] , V_65 ) ;
memcpy ( V_56 -> V_73 . V_20 + V_69 ,
& V_71 [ 1 * V_67 + V_68 ] , V_65 ) ;
memcpy ( V_56 -> V_73 . V_21 + V_69 ,
& V_71 [ 2 * V_67 + V_68 ] , V_65 ) ;
memcpy ( V_56 -> V_73 . V_22 + V_69 ,
& V_71 [ 3 * V_67 + V_68 ] , V_65 ) ;
V_68 += V_66 ;
V_69 += V_56 -> V_11 . V_10 ;
}
F_9 ( L_1 ) ;
}
struct V_57 *
F_19 (
const struct V_77 * V_11 )
{
struct V_57 * V_78 ;
int V_9 ;
assert ( V_11 != NULL ) ;
F_7 ( L_9 , V_11 ) ;
if ( ! V_11 -> V_79 )
return NULL ;
V_78 = F_20 ( 1 , sizeof( * V_78 ) ) ;
if ( ! V_78 )
goto V_80;
V_9 = F_18 ( sizeof( int ) * V_11 -> V_10 , V_76 )
* V_11 -> V_24 * V_15 ;
V_78 -> V_9 = 2 * V_9 ;
V_78 -> V_63 = F_21 ( V_78 -> V_9 ) ;
if ( V_78 -> V_63 == V_81 )
goto V_80;
V_78 -> V_74 = V_78 -> V_63 ;
V_78 -> V_82 = V_9 ;
V_78 -> V_75 = V_78 -> V_63 + V_9 ;
V_78 -> V_83 = V_9 ;
F_9 ( L_10 , V_78 ) ;
return V_78 ;
V_80:
F_22 ( V_78 ) ;
F_9 ( L_10 , NULL ) ;
return NULL ;
}
void
F_22 ( struct V_57 * V_78 )
{
if ( V_78 != NULL ) {
F_23 ( V_78 -> V_63 ) ;
F_24 ( V_78 ) ;
}
}
void F_25 (
const struct V_7 * V_84 , unsigned V_85 )
{
( void ) V_84 ;
( void ) V_85 ;
}
void F_26 (
const struct V_7 * V_84 , unsigned V_85 )
{
( void ) V_84 ;
( void ) V_85 ;
}
void F_27 (
const struct V_7 * V_84 , unsigned V_85 )
{
( void ) V_84 ;
( void ) V_85 ;
}
void F_28 (
const struct V_7 * V_84 , unsigned V_85 )
{
( void ) V_84 ;
( void ) V_85 ;
}
