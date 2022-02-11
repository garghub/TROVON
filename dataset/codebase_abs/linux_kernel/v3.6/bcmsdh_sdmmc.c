static bool
F_1 ( struct V_1 * V_2 )
{
bool V_3 = false ;
#ifdef F_2
V_3 = F_3 ( & V_2 -> V_4 ) ;
#endif
return V_3 ;
}
static void
F_4 ( struct V_1 * V_2 , T_1 * V_5 )
{
#ifdef F_2
int V_6 = 0 ;
while ( F_3 ( & V_2 -> V_4 ) && V_6 ++ != 30 )
F_5 ( * V_5 , false , V_7 / 100 ) ;
#endif
}
static inline int F_6 ( struct V_1 * V_2 ,
T_2 V_8 , T_3 * V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 [ 0 ] ;
int V_13 ;
if ( V_8 == V_14 ) {
V_11 = V_2 -> V_12 [ 2 ] ;
if ( V_11 ) {
F_7 ( V_11 ) ;
if ( * V_9 & V_15 ) {
V_13 = F_8 ( V_11 ) ;
if ( V_13 )
F_9 ( ERROR ,
L_1 ,
V_13 ) ;
} else {
V_13 = F_10 ( V_11 ) ;
if ( V_13 )
F_9 ( ERROR ,
L_2 ,
V_13 ) ;
}
F_11 ( V_11 ) ;
}
} else if ( ( V_8 == V_16 ) ||
( V_8 == V_17 ) ) {
V_11 = F_12 ( V_2 -> V_12 [ 0 ] , sizeof( struct V_10 ) ,
V_18 ) ;
if ( ! V_11 )
return - V_19 ;
V_11 -> V_20 = 0 ;
F_7 ( V_11 ) ;
F_13 ( V_11 , * V_9 , V_8 , & V_13 ) ;
F_11 ( V_11 ) ;
F_14 ( V_11 ) ;
} else if ( V_8 < 0xF0 ) {
F_9 ( ERROR , L_3 , V_8 ) ;
V_13 = - V_21 ;
} else {
F_7 ( V_11 ) ;
F_15 ( V_11 , * V_9 , V_8 , & V_13 ) ;
F_11 ( V_11 ) ;
}
return V_13 ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_22 , T_2 V_12 ,
T_2 V_8 , T_3 * V_9 )
{
int V_13 ;
F_9 ( V_23 , L_4 , V_22 , V_12 , V_8 ) ;
F_4 ( V_2 , & V_2 -> V_24 ) ;
if ( F_1 ( V_2 ) )
return - V_25 ;
if ( V_22 && V_12 == 0 ) {
V_13 = F_6 ( V_2 , V_8 , V_9 ) ;
} else {
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
if ( V_22 )
F_13 ( V_2 -> V_12 [ V_12 ] , * V_9 , V_8 ,
& V_13 ) ;
else if ( V_12 == 0 ) {
* V_9 = F_17 ( V_2 -> V_12 [ V_12 ] , V_8 ,
& V_13 ) ;
} else {
* V_9 = F_18 ( V_2 -> V_12 [ V_12 ] , V_8 ,
& V_13 ) ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
}
if ( V_13 )
F_9 ( ERROR , L_5 ,
V_22 ? L_6 : L_7 , V_12 , V_8 , * V_9 , V_13 ) ;
return V_13 ;
}
int F_19 ( struct V_1 * V_2 ,
T_2 V_22 , T_2 V_12 , T_2 V_26 , T_4 * V_27 ,
T_2 V_28 )
{
int V_13 = - V_25 ;
if ( V_12 == 0 ) {
F_9 ( ERROR , L_8 ) ;
return - V_29 ;
}
F_9 ( V_23 , L_9 ,
V_22 , V_12 , V_26 , V_28 ) ;
F_4 ( V_2 , & V_2 -> V_30 ) ;
if ( F_1 ( V_2 ) )
return - V_25 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
if ( V_22 ) {
if ( V_28 == 4 )
F_20 ( V_2 -> V_12 [ V_12 ] , * V_27 , V_26 ,
& V_13 ) ;
else if ( V_28 == 2 )
F_21 ( V_2 -> V_12 [ V_12 ] , ( * V_27 & 0xFFFF ) ,
V_26 , & V_13 ) ;
else
F_9 ( ERROR , L_10 , V_28 ) ;
} else {
if ( V_28 == 4 )
* V_27 = F_22 ( V_2 -> V_12 [ V_12 ] , V_26 , & V_13 ) ;
else if ( V_28 == 2 )
* V_27 = F_23 ( V_2 -> V_12 [ V_12 ] , V_26 ,
& V_13 ) & 0xFFFF ;
else
F_9 ( ERROR , L_10 , V_28 ) ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
if ( V_13 )
F_9 ( ERROR , L_11 ,
V_22 ? L_6 : L_7 , V_13 ) ;
return V_13 ;
}
static int
F_24 ( struct V_1 * V_2 , T_2 V_31 , bool V_32 ,
T_2 V_12 , T_2 V_26 , struct V_33 * V_34 , T_2 V_35 )
{
int V_13 = 0 ;
if ( ( V_31 ) && ( ! V_32 ) ) {
V_13 = F_25 ( V_2 -> V_12 [ V_12 ] , V_26 ,
( ( T_3 * ) ( V_34 -> V_36 ) ) , V_35 ) ;
} else if ( V_31 ) {
V_13 = F_25 ( V_2 -> V_12 [ V_12 ] , V_26 ,
( ( T_3 * ) ( V_34 -> V_36 ) ) , V_35 ) ;
} else if ( V_32 ) {
V_13 = F_26 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_34 -> V_36 ) ) , V_26 , V_35 ) ;
} else {
V_13 = F_27 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_34 -> V_36 ) ) ,
V_26 , V_35 ) ;
}
return V_13 ;
}
int
F_28 ( struct V_1 * V_2 , T_2 V_37 ,
T_2 V_31 , T_2 V_12 , T_2 V_26 ,
struct V_38 * V_39 )
{
bool V_32 = ( V_37 == V_40 ) ;
T_4 V_41 = 0 ;
int V_13 = 0 ;
struct V_33 * V_34 ;
F_9 ( V_42 , L_12 ) ;
F_4 ( V_2 , & V_2 -> V_43 ) ;
if ( F_1 ( V_2 ) )
return - V_25 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
F_29 (pktq, pkt) {
T_2 V_44 = V_34 -> V_45 ;
V_44 += 3 ;
V_44 &= 0xFFFFFFFC ;
V_13 = F_24 ( V_2 , V_31 , V_32 , V_12 ,
V_26 , V_34 , V_44 ) ;
if ( V_13 ) {
F_9 ( ERROR , L_13 ,
V_31 ? L_14 : L_15 , V_34 , V_41 , V_26 ,
V_44 , V_13 ) ;
} else {
F_9 ( V_42 , L_16 ,
V_31 ? L_14 : L_15 , V_34 , V_41 , V_26 ,
V_44 ) ;
}
if ( ! V_32 )
V_26 += V_44 ;
V_41 ++ ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
F_9 ( V_42 , L_17 ) ;
return V_13 ;
}
int F_30 ( struct V_1 * V_2 ,
T_2 V_37 , T_2 V_31 , T_2 V_12 , T_2 V_26 ,
struct V_33 * V_34 )
{
int V_46 ;
T_2 V_44 ;
bool V_32 = ( V_37 == V_40 ) ;
F_9 ( V_42 , L_12 ) ;
if ( V_34 == NULL )
return - V_29 ;
V_44 = V_34 -> V_45 ;
F_4 ( V_2 , & V_2 -> V_47 ) ;
if ( F_1 ( V_2 ) )
return - V_25 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
V_44 += 3 ;
V_44 &= ( T_2 ) ~ 3 ;
V_46 = F_24 ( V_2 , V_31 , V_32 , V_12 ,
V_26 , V_34 , V_44 ) ;
if ( V_46 ) {
F_9 ( ERROR , L_18 ,
V_31 ? L_14 : L_15 , V_34 , V_26 , V_44 , V_46 ) ;
} else {
F_9 ( V_42 , L_19 ,
V_31 ? L_14 : L_15 , V_34 , V_26 , V_44 ) ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
return V_46 ;
}
static int F_31 ( struct V_1 * V_2 , T_4 V_8 )
{
int V_48 , V_49 ;
T_4 V_50 , V_51 ;
T_5 V_52 ;
T_3 * V_53 = ( T_3 * ) & V_52 ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
V_51 = F_32 ( V_2 , V_8 , & V_49 ) ;
if ( V_49 != 0 )
F_9 ( ERROR , L_20 ) ;
* V_53 ++ = ( T_3 ) V_51 ;
V_8 ++ ;
}
V_50 = F_33 ( V_52 ) ;
V_50 &= 0x0001FFFF ;
return V_50 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_13 ;
T_4 V_54 ;
T_3 V_12 ;
F_9 ( V_42 , L_21 ) ;
V_2 -> V_55 [ 0 ] = F_31 ( V_2 ,
V_56 ) ;
F_9 ( V_23 , L_22 ,
V_2 -> V_55 [ 0 ] ) ;
for ( V_54 = F_35 ( 1 ) , V_12 = 1 ;
V_12 <= V_2 -> V_57 ; V_12 ++ , V_54 += V_58 ) {
V_2 -> V_55 [ V_12 ] =
F_31 ( V_2 , V_59 + V_54 ) ;
F_9 ( V_23 , L_23 ,
V_12 , V_2 -> V_55 [ V_12 ] ) ;
}
F_7 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_8 ( V_2 -> V_12 [ 1 ] ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 )
F_9 ( ERROR , L_24 , V_13 ) ;
return false ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_9 ( V_42 , L_21 ) ;
V_2 -> V_57 = 2 ;
F_7 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_37 ( V_2 -> V_12 [ 1 ] , V_60 ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 ) {
F_9 ( ERROR , L_25 ) ;
goto V_61;
}
F_7 ( V_2 -> V_12 [ 2 ] ) ;
V_13 = F_37 ( V_2 -> V_12 [ 2 ] , V_62 ) ;
F_11 ( V_2 -> V_12 [ 2 ] ) ;
if ( V_13 ) {
F_9 ( ERROR , L_26 ) ;
goto V_61;
}
F_34 ( V_2 ) ;
V_61:
F_9 ( V_42 , L_27 ) ;
return V_13 ;
}
void F_38 ( struct V_1 * V_2 )
{
F_9 ( V_42 , L_21 ) ;
F_7 ( V_2 -> V_12 [ 2 ] ) ;
F_10 ( V_2 -> V_12 [ 2 ] ) ;
F_11 ( V_2 -> V_12 [ 2 ] ) ;
F_7 ( V_2 -> V_12 [ 1 ] ) ;
F_10 ( V_2 -> V_12 [ 1 ] ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
if ( F_40 ( & V_65 ) ) {
F_9 ( ERROR , L_28 ) ;
return - V_66 ;
}
V_64 = F_41 ( & V_65 , struct V_63 ,
V_67 ) ;
V_2 -> V_68 = V_64 -> V_68 ;
V_2 -> V_69 = V_64 -> V_70 ;
F_42 ( & V_64 -> V_67 ) ;
F_14 ( V_64 ) ;
return 0 ;
}
static inline int F_39 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_43 ( struct V_10 * V_12 ,
const struct V_71 * V_72 )
{
int V_49 = 0 ;
struct V_1 * V_2 ;
struct V_73 * V_74 ;
F_9 ( V_42 , L_12 ) ;
F_9 ( V_42 , L_29 , V_12 -> V_75 ) ;
F_9 ( V_42 , L_30 , V_12 -> V_76 ) ;
F_9 ( V_42 , L_31 , V_12 -> V_77 ) ;
F_9 ( V_42 , L_32 , V_12 -> V_20 ) ;
if ( V_12 -> V_20 == 1 ) {
if ( F_44 ( & V_12 -> V_78 -> V_79 ) ) {
F_9 ( ERROR , L_33 ) ;
return - V_66 ;
}
V_74 = F_45 ( sizeof( struct V_73 ) , V_18 ) ;
if ( ! V_74 )
return - V_19 ;
V_2 = F_45 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_2 ) {
F_14 ( V_74 ) ;
return - V_19 ;
}
V_2 -> V_12 [ 0 ] = V_12 ;
V_2 -> V_12 [ 1 ] = V_12 ;
V_2 -> V_74 = V_74 ;
V_74 -> V_80 . V_81 = V_2 ;
V_74 -> type = V_82 ;
V_74 -> V_83 = V_84 ;
F_46 ( & V_12 -> V_78 -> V_79 , V_2 ) ;
F_47 ( & V_2 -> V_4 , false ) ;
F_48 ( & V_2 -> V_24 ) ;
F_48 ( & V_2 -> V_30 ) ;
F_48 ( & V_2 -> V_43 ) ;
F_48 ( & V_2 -> V_47 ) ;
}
if ( V_12 -> V_20 == 2 ) {
V_2 = F_44 ( & V_12 -> V_78 -> V_79 ) ;
if ( ( ! V_2 ) || ( V_2 -> V_12 [ 1 ] -> V_78 != V_12 -> V_78 ) )
return - V_85 ;
V_49 = F_39 ( V_2 ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_12 [ 2 ] = V_12 ;
V_74 = V_2 -> V_74 ;
V_2 -> V_79 = & V_12 -> V_79 ;
F_46 ( & V_12 -> V_79 , V_74 ) ;
F_9 ( V_42 , L_34 ) ;
V_49 = F_49 ( V_2 ) ;
}
return V_49 ;
}
static void F_50 ( struct V_10 * V_12 )
{
struct V_73 * V_74 ;
struct V_1 * V_2 ;
F_9 ( V_42 , L_12 ) ;
F_9 ( V_23 , L_29 , V_12 -> V_75 ) ;
F_9 ( V_23 , L_30 , V_12 -> V_76 ) ;
F_9 ( V_23 , L_31 , V_12 -> V_77 ) ;
F_9 ( V_23 , L_32 , V_12 -> V_20 ) ;
if ( V_12 -> V_20 == 2 ) {
V_74 = F_44 ( & V_12 -> V_79 ) ;
V_2 = V_74 -> V_80 . V_81 ;
F_9 ( V_42 , L_35 ) ;
F_51 ( V_2 ) ;
F_46 ( & V_12 -> V_78 -> V_79 , NULL ) ;
F_46 ( & V_12 -> V_79 , NULL ) ;
F_14 ( V_74 ) ;
F_14 ( V_2 ) ;
}
}
static int F_52 ( struct V_77 * V_79 )
{
T_6 V_86 ;
struct V_10 * V_12 = F_53 ( V_79 ) ;
struct V_1 * V_2 = F_44 ( & V_12 -> V_78 -> V_79 ) ;
int V_49 = 0 ;
F_9 ( V_42 , L_21 ) ;
F_47 ( & V_2 -> V_4 , true ) ;
V_86 = F_54 ( V_2 -> V_12 [ 1 ] ) ;
if ( ! ( V_86 & V_87 ) ) {
F_9 ( ERROR , L_36 ) ;
return - V_29 ;
}
V_49 = F_55 ( V_2 -> V_12 [ 1 ] , V_87 ) ;
if ( V_49 ) {
F_9 ( ERROR , L_37 ) ;
return V_49 ;
}
F_56 ( V_2 , false ) ;
return V_49 ;
}
static int F_57 ( struct V_77 * V_79 )
{
struct V_10 * V_12 = F_53 ( V_79 ) ;
struct V_1 * V_2 = F_44 ( & V_12 -> V_78 -> V_79 ) ;
F_56 ( V_2 , true ) ;
F_47 ( & V_2 -> V_4 , false ) ;
return 0 ;
}
static int F_58 ( struct V_88 * V_89 )
{
struct V_90 * V_91 ;
struct V_63 * V_64 ;
int V_48 , V_49 ;
F_59 ( & V_65 ) ;
for ( V_48 = 0 ; ; V_48 ++ ) {
V_91 = F_60 ( V_89 , V_92 , V_48 ) ;
if ( ! V_91 )
break;
V_64 = F_45 ( sizeof( struct V_63 ) ,
V_18 ) ;
if ( ! V_64 )
return - V_19 ;
V_64 -> V_68 = V_91 -> V_93 ;
V_64 -> V_70 = V_91 -> V_70 & V_94 ;
F_61 ( & V_64 -> V_67 , & V_65 ) ;
}
if ( V_48 == 0 )
return - V_66 ;
V_49 = F_62 ( & V_95 ) ;
if ( V_49 )
F_9 ( ERROR , L_38 , V_49 ) ;
return V_49 ;
}
void F_63 ( void )
{
F_9 ( V_42 , L_12 ) ;
F_64 ( & V_95 ) ;
F_65 ( & V_96 ) ;
}
void F_66 ( void )
{
int V_49 ;
F_9 ( V_42 , L_12 ) ;
V_49 = F_67 ( & V_96 ) ;
if ( V_49 )
F_9 ( ERROR , L_39 , V_49 ) ;
}
void F_63 ( void )
{
F_9 ( V_42 , L_12 ) ;
F_64 ( & V_95 ) ;
}
void F_66 ( void )
{
int V_49 ;
F_9 ( V_42 , L_12 ) ;
V_49 = F_62 ( & V_95 ) ;
if ( V_49 )
F_9 ( ERROR , L_38 , V_49 ) ;
}
