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
if ( * V_9 & V_15 ) {
V_13 = F_7 ( V_11 ) ;
if ( V_13 )
F_8 ( L_1 ,
V_13 ) ;
} else {
V_13 = F_9 ( V_11 ) ;
if ( V_13 )
F_8 ( L_2 ,
V_13 ) ;
}
}
} else if ( ( V_8 == V_16 ) ||
( V_8 == V_17 ) ) {
V_11 = F_10 ( V_2 -> V_12 [ 0 ] , sizeof( struct V_10 ) ,
V_18 ) ;
if ( ! V_11 )
return - V_19 ;
V_11 -> V_20 = 0 ;
F_11 ( V_11 , * V_9 , V_8 , & V_13 ) ;
F_12 ( V_11 ) ;
} else if ( V_8 < 0xF0 ) {
F_8 ( L_3 , V_8 ) ;
V_13 = - V_21 ;
} else {
F_13 ( V_11 , * V_9 , V_8 , & V_13 ) ;
}
return V_13 ;
}
int F_14 ( struct V_1 * V_2 , T_2 V_22 , T_2 V_12 ,
T_2 V_8 , T_3 * V_9 )
{
int V_13 ;
F_15 ( V_23 , L_4 , V_22 , V_12 , V_8 ) ;
F_4 ( V_2 , & V_2 -> V_24 ) ;
if ( F_1 ( V_2 ) )
return - V_25 ;
if ( V_22 && V_12 == 0 ) {
V_13 = F_6 ( V_2 , V_8 , V_9 ) ;
} else {
if ( V_22 )
F_11 ( V_2 -> V_12 [ V_12 ] , * V_9 , V_8 ,
& V_13 ) ;
else if ( V_12 == 0 ) {
* V_9 = F_16 ( V_2 -> V_12 [ V_12 ] , V_8 ,
& V_13 ) ;
} else {
* V_9 = F_17 ( V_2 -> V_12 [ V_12 ] , V_8 ,
& V_13 ) ;
}
}
if ( V_13 )
F_8 ( L_5 ,
V_22 ? L_6 : L_7 , V_12 , V_8 , * V_9 , V_13 ) ;
return V_13 ;
}
int F_18 ( struct V_1 * V_2 ,
T_2 V_22 , T_2 V_12 , T_2 V_26 , T_4 * V_27 ,
T_2 V_28 )
{
int V_13 = - V_25 ;
if ( V_12 == 0 ) {
F_8 ( L_8 ) ;
return - V_29 ;
}
F_15 ( V_23 , L_9 ,
V_22 , V_12 , V_26 , V_28 ) ;
F_4 ( V_2 , & V_2 -> V_30 ) ;
if ( F_1 ( V_2 ) )
return - V_25 ;
if ( V_22 ) {
if ( V_28 == 4 )
F_19 ( V_2 -> V_12 [ V_12 ] , * V_27 , V_26 ,
& V_13 ) ;
else if ( V_28 == 2 )
F_20 ( V_2 -> V_12 [ V_12 ] , ( * V_27 & 0xFFFF ) ,
V_26 , & V_13 ) ;
else
F_8 ( L_10 , V_28 ) ;
} else {
if ( V_28 == 4 )
* V_27 = F_21 ( V_2 -> V_12 [ V_12 ] , V_26 , & V_13 ) ;
else if ( V_28 == 2 )
* V_27 = F_22 ( V_2 -> V_12 [ V_12 ] , V_26 ,
& V_13 ) & 0xFFFF ;
else
F_8 ( L_10 , V_28 ) ;
}
if ( V_13 )
F_8 ( L_11 ,
V_22 ? L_6 : L_7 , V_13 ) ;
return V_13 ;
}
static int
F_23 ( struct V_1 * V_2 , T_2 V_31 , bool V_32 ,
T_2 V_12 , T_2 V_26 , struct V_33 * V_34 , T_2 V_35 )
{
int V_13 = 0 ;
if ( ( V_31 ) && ( ! V_32 ) ) {
V_13 = F_24 ( V_2 -> V_12 [ V_12 ] , V_26 ,
( ( T_3 * ) ( V_34 -> V_36 ) ) , V_35 ) ;
} else if ( V_31 ) {
V_13 = F_24 ( V_2 -> V_12 [ V_12 ] , V_26 ,
( ( T_3 * ) ( V_34 -> V_36 ) ) , V_35 ) ;
} else if ( V_32 ) {
V_13 = F_25 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_34 -> V_36 ) ) , V_26 , V_35 ) ;
} else {
V_13 = F_26 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_34 -> V_36 ) ) ,
V_26 , V_35 ) ;
}
return V_13 ;
}
int
F_27 ( struct V_1 * V_2 , T_2 V_37 ,
T_2 V_31 , T_2 V_12 , T_2 V_26 ,
struct V_38 * V_39 )
{
bool V_32 = ( V_37 == V_40 ) ;
T_4 V_41 = 0 ;
int V_13 = 0 ;
struct V_33 * V_34 ;
F_15 ( V_23 , L_12 ) ;
F_4 ( V_2 , & V_2 -> V_42 ) ;
if ( F_1 ( V_2 ) )
return - V_25 ;
F_28 (pktq, pkt) {
T_2 V_43 = V_34 -> V_44 ;
V_43 += 3 ;
V_43 &= 0xFFFFFFFC ;
V_13 = F_23 ( V_2 , V_31 , V_32 , V_12 ,
V_26 , V_34 , V_43 ) ;
if ( V_13 ) {
F_8 ( L_13 ,
V_31 ? L_14 : L_15 , V_34 , V_41 , V_26 ,
V_43 , V_13 ) ;
} else {
F_15 ( V_23 , L_16 ,
V_31 ? L_14 : L_15 , V_34 , V_41 , V_26 ,
V_43 ) ;
}
if ( ! V_32 )
V_26 += V_43 ;
V_41 ++ ;
}
F_15 ( V_23 , L_17 ) ;
return V_13 ;
}
int F_29 ( struct V_1 * V_2 ,
T_2 V_37 , T_2 V_31 , T_2 V_12 , T_2 V_26 ,
struct V_33 * V_34 )
{
int V_45 ;
T_2 V_43 ;
bool V_32 = ( V_37 == V_40 ) ;
F_15 ( V_23 , L_12 ) ;
if ( V_34 == NULL )
return - V_29 ;
V_43 = V_34 -> V_44 ;
F_4 ( V_2 , & V_2 -> V_46 ) ;
if ( F_1 ( V_2 ) )
return - V_25 ;
V_43 += 3 ;
V_43 &= ( T_2 ) ~ 3 ;
V_45 = F_23 ( V_2 , V_31 , V_32 , V_12 ,
V_26 , V_34 , V_43 ) ;
if ( V_45 ) {
F_8 ( L_18 ,
V_31 ? L_14 : L_15 , V_34 , V_26 , V_43 , V_45 ) ;
} else {
F_15 ( V_23 , L_19 ,
V_31 ? L_14 : L_15 , V_34 , V_26 , V_43 ) ;
}
return V_45 ;
}
static int F_30 ( struct V_1 * V_2 , T_4 V_8 )
{
int V_47 , V_48 ;
T_4 V_49 , V_50 ;
T_5 V_51 ;
T_3 * V_52 = ( T_3 * ) & V_51 ;
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_50 = F_31 ( V_2 , V_8 , & V_48 ) ;
if ( V_48 != 0 )
F_8 ( L_20 ) ;
* V_52 ++ = ( T_3 ) V_50 ;
V_8 ++ ;
}
V_49 = F_32 ( V_51 ) ;
V_49 &= 0x0001FFFF ;
return V_49 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_13 ;
T_4 V_53 ;
T_3 V_12 ;
F_15 ( V_23 , L_21 ) ;
V_2 -> V_54 [ 0 ] = F_30 ( V_2 ,
V_55 ) ;
F_15 ( V_23 , L_22 ,
V_2 -> V_54 [ 0 ] ) ;
for ( V_53 = F_34 ( 1 ) , V_12 = 1 ;
V_12 <= V_2 -> V_56 ; V_12 ++ , V_53 += V_57 ) {
V_2 -> V_54 [ V_12 ] =
F_30 ( V_2 , V_58 + V_53 ) ;
F_15 ( V_23 , L_23 ,
V_12 , V_2 -> V_54 [ V_12 ] ) ;
}
V_13 = F_7 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 )
F_8 ( L_24 , V_13 ) ;
return false ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_15 ( V_23 , L_21 ) ;
V_2 -> V_56 = 2 ;
F_36 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_37 ( V_2 -> V_12 [ 1 ] , V_59 ) ;
if ( V_13 ) {
F_8 ( L_25 ) ;
goto V_60;
}
V_13 = F_37 ( V_2 -> V_12 [ 2 ] , V_61 ) ;
if ( V_13 ) {
F_8 ( L_26 ) ;
goto V_60;
}
F_33 ( V_2 ) ;
V_60:
F_38 ( V_2 -> V_12 [ 1 ] ) ;
F_15 ( V_23 , L_27 ) ;
return V_13 ;
}
void F_39 ( struct V_1 * V_2 )
{
F_15 ( V_23 , L_21 ) ;
F_36 ( V_2 -> V_12 [ 2 ] ) ;
F_9 ( V_2 -> V_12 [ 2 ] ) ;
F_38 ( V_2 -> V_12 [ 2 ] ) ;
F_36 ( V_2 -> V_12 [ 1 ] ) ;
F_9 ( V_2 -> V_12 [ 1 ] ) ;
F_38 ( V_2 -> V_12 [ 1 ] ) ;
}
static int F_40 ( struct V_10 * V_12 ,
const struct V_62 * V_63 )
{
int V_64 ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
F_15 ( V_23 , L_12 ) ;
F_15 ( V_23 , L_28 , V_12 -> V_67 ) ;
F_15 ( V_23 , L_29 , V_12 -> V_68 ) ;
F_15 ( V_23 , L_30 , V_12 -> V_69 ) ;
F_15 ( V_23 , L_31 , V_12 -> V_20 ) ;
if ( V_12 -> V_20 == 1 )
return 0 ;
if ( V_12 -> V_20 != 2 )
return - V_70 ;
V_66 = F_41 ( sizeof( struct V_65 ) , V_18 ) ;
if ( ! V_66 )
return - V_19 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_2 ) {
F_12 ( V_66 ) ;
return - V_19 ;
}
V_2 -> V_12 [ 0 ] = V_12 -> V_71 -> V_10 [ 0 ] ;
V_2 -> V_12 [ 1 ] = V_12 -> V_71 -> V_10 [ 0 ] ;
V_2 -> V_12 [ 2 ] = V_12 ;
V_2 -> V_66 = V_66 ;
V_66 -> V_72 . V_73 = V_2 ;
V_66 -> V_74 = V_75 ;
F_42 ( & V_12 -> V_76 , V_66 ) ;
F_42 ( & V_2 -> V_12 [ 1 ] -> V_76 , V_66 ) ;
V_2 -> V_76 = & V_2 -> V_12 [ 1 ] -> V_76 ;
V_2 -> V_77 = V_78 ;
F_43 ( & V_2 -> V_4 , false ) ;
F_44 ( & V_2 -> V_24 ) ;
F_44 ( & V_2 -> V_30 ) ;
F_44 ( & V_2 -> V_42 ) ;
F_44 ( & V_2 -> V_46 ) ;
F_15 ( V_23 , L_32 ) ;
V_64 = F_45 ( V_2 ) ;
if ( V_64 ) {
F_8 ( L_33 , V_64 ) ;
goto V_79;
}
F_15 ( V_23 , L_34 ) ;
return 0 ;
V_79:
F_42 ( & V_12 -> V_76 , NULL ) ;
F_42 ( & V_2 -> V_12 [ 1 ] -> V_76 , NULL ) ;
F_12 ( V_2 ) ;
F_12 ( V_66 ) ;
return V_64 ;
}
static void F_46 ( struct V_10 * V_12 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 ;
F_15 ( V_23 , L_12 ) ;
F_15 ( V_23 , L_29 , V_12 -> V_68 ) ;
F_15 ( V_23 , L_30 , V_12 -> V_69 ) ;
F_15 ( V_23 , L_35 , V_12 -> V_20 ) ;
if ( V_12 -> V_20 != 1 && V_12 -> V_20 != 2 )
return;
V_66 = F_47 ( & V_12 -> V_76 ) ;
if ( V_66 ) {
V_2 = V_66 -> V_72 . V_73 ;
F_48 ( V_2 ) ;
F_42 ( & V_2 -> V_12 [ 1 ] -> V_76 , NULL ) ;
F_42 ( & V_2 -> V_12 [ 2 ] -> V_76 , NULL ) ;
F_12 ( V_66 ) ;
F_12 ( V_2 ) ;
}
F_15 ( V_23 , L_17 ) ;
}
static int F_49 ( struct V_69 * V_76 )
{
T_6 V_80 ;
struct V_65 * V_66 = F_47 ( V_76 ) ;
struct V_1 * V_2 = V_66 -> V_72 . V_73 ;
int V_48 = 0 ;
F_15 ( V_23 , L_21 ) ;
F_43 ( & V_2 -> V_4 , true ) ;
V_80 = F_50 ( V_2 -> V_12 [ 1 ] ) ;
if ( ! ( V_80 & V_81 ) ) {
F_8 ( L_36 ) ;
return - V_29 ;
}
V_48 = F_51 ( V_2 -> V_12 [ 1 ] , V_81 ) ;
if ( V_48 ) {
F_8 ( L_37 ) ;
return V_48 ;
}
F_52 ( V_2 , false ) ;
return V_48 ;
}
static int F_53 ( struct V_69 * V_76 )
{
struct V_65 * V_66 = F_47 ( V_76 ) ;
struct V_1 * V_2 = V_66 -> V_72 . V_73 ;
F_52 ( V_2 , true ) ;
F_43 ( & V_2 -> V_4 , false ) ;
return 0 ;
}
static int F_54 ( struct V_82 * V_83 )
{
int V_48 ;
F_15 ( V_23 , L_12 ) ;
V_78 = V_83 -> V_76 . V_84 ;
if ( V_78 -> V_85 )
V_78 -> V_85 () ;
V_48 = F_55 ( & V_86 ) ;
if ( V_48 )
F_8 ( L_38 , V_48 ) ;
return V_48 ;
}
static int F_56 ( struct V_82 * V_83 )
{
F_15 ( V_23 , L_12 ) ;
if ( V_78 -> V_87 )
V_78 -> V_87 () ;
F_57 ( & V_86 ) ;
return 0 ;
}
void F_58 ( void )
{
F_15 ( V_23 , L_12 ) ;
if ( V_78 )
F_59 ( & V_88 ) ;
else
F_57 ( & V_86 ) ;
}
void F_60 ( void )
{
int V_48 ;
F_15 ( V_23 , L_12 ) ;
V_48 = F_61 ( & V_88 , F_54 ) ;
if ( V_48 == - V_70 ) {
F_15 ( V_23 , L_39 ) ;
V_48 = F_55 ( & V_86 ) ;
}
if ( V_48 )
F_8 ( L_40 , V_48 ) ;
}
