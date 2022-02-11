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
} else if ( V_8 == V_16 ) {
F_7 ( V_11 ) ;
F_12 ( V_11 , * V_9 , V_8 , & V_13 ) ;
F_11 ( V_11 ) ;
} else if ( V_8 < 0xF0 ) {
F_9 ( ERROR , L_3 , V_8 ) ;
V_13 = - V_17 ;
} else {
F_7 ( V_11 ) ;
F_13 ( V_11 , * V_9 , V_8 , & V_13 ) ;
F_11 ( V_11 ) ;
}
return V_13 ;
}
int F_14 ( struct V_1 * V_2 , T_2 V_18 , T_2 V_12 ,
T_2 V_8 , T_3 * V_9 )
{
int V_13 ;
F_9 ( V_19 , L_4 , V_18 , V_12 , V_8 ) ;
F_4 ( V_2 , & V_2 -> V_20 ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
if ( V_18 && V_12 == 0 ) {
V_13 = F_6 ( V_2 , V_8 , V_9 ) ;
} else {
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
if ( V_18 )
F_12 ( V_2 -> V_12 [ V_12 ] , * V_9 , V_8 ,
& V_13 ) ;
else if ( V_12 == 0 ) {
* V_9 = F_15 ( V_2 -> V_12 [ V_12 ] , V_8 ,
& V_13 ) ;
} else {
* V_9 = F_16 ( V_2 -> V_12 [ V_12 ] , V_8 ,
& V_13 ) ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
}
if ( V_13 )
F_9 ( ERROR , L_5 ,
V_18 ? L_6 : L_7 , V_12 , V_8 , * V_9 , V_13 ) ;
return V_13 ;
}
int F_17 ( struct V_1 * V_2 ,
T_2 V_18 , T_2 V_12 , T_2 V_22 , T_4 * V_23 ,
T_2 V_24 )
{
int V_13 = - V_21 ;
if ( V_12 == 0 ) {
F_9 ( ERROR , L_8 ) ;
return - V_25 ;
}
F_9 ( V_19 , L_9 ,
V_18 , V_12 , V_22 , V_24 ) ;
F_4 ( V_2 , & V_2 -> V_26 ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
if ( V_18 ) {
if ( V_24 == 4 )
F_18 ( V_2 -> V_12 [ V_12 ] , * V_23 , V_22 ,
& V_13 ) ;
else if ( V_24 == 2 )
F_19 ( V_2 -> V_12 [ V_12 ] , ( * V_23 & 0xFFFF ) ,
V_22 , & V_13 ) ;
else
F_9 ( ERROR , L_10 , V_24 ) ;
} else {
if ( V_24 == 4 )
* V_23 = F_20 ( V_2 -> V_12 [ V_12 ] , V_22 , & V_13 ) ;
else if ( V_24 == 2 )
* V_23 = F_21 ( V_2 -> V_12 [ V_12 ] , V_22 ,
& V_13 ) & 0xFFFF ;
else
F_9 ( ERROR , L_10 , V_24 ) ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
if ( V_13 )
F_9 ( ERROR , L_11 ,
V_18 ? L_6 : L_7 , V_13 ) ;
return V_13 ;
}
static int
F_22 ( struct V_1 * V_2 , T_2 V_27 , bool V_28 ,
T_2 V_12 , T_2 V_22 , struct V_29 * V_30 , T_2 V_31 )
{
int V_13 = 0 ;
if ( ( V_27 ) && ( ! V_28 ) ) {
V_13 = F_23 ( V_2 -> V_12 [ V_12 ] , V_22 ,
( ( T_3 * ) ( V_30 -> V_32 ) ) , V_31 ) ;
} else if ( V_27 ) {
V_13 = F_23 ( V_2 -> V_12 [ V_12 ] , V_22 ,
( ( T_3 * ) ( V_30 -> V_32 ) ) , V_31 ) ;
} else if ( V_28 ) {
V_13 = F_24 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_30 -> V_32 ) ) , V_22 , V_31 ) ;
} else {
V_13 = F_25 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_30 -> V_32 ) ) ,
V_22 , V_31 ) ;
}
return V_13 ;
}
int
F_26 ( struct V_1 * V_2 , T_2 V_33 ,
T_2 V_27 , T_2 V_12 , T_2 V_22 ,
struct V_34 * V_35 )
{
bool V_28 = ( V_33 == V_36 ) ;
T_4 V_37 = 0 ;
int V_13 = 0 ;
struct V_29 * V_30 ;
F_9 ( V_38 , L_12 ) ;
F_4 ( V_2 , & V_2 -> V_39 ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
F_27 (pktq, pkt) {
T_2 V_40 = V_30 -> V_41 ;
V_40 += 3 ;
V_40 &= 0xFFFFFFFC ;
V_13 = F_22 ( V_2 , V_27 , V_28 , V_12 ,
V_22 , V_30 , V_40 ) ;
if ( V_13 ) {
F_9 ( ERROR , L_13 ,
V_27 ? L_14 : L_15 , V_30 , V_37 , V_22 ,
V_40 , V_13 ) ;
} else {
F_9 ( V_38 , L_16 ,
V_27 ? L_14 : L_15 , V_30 , V_37 , V_22 ,
V_40 ) ;
}
if ( ! V_28 )
V_22 += V_40 ;
V_37 ++ ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
F_9 ( V_38 , L_17 ) ;
return V_13 ;
}
int F_28 ( struct V_1 * V_2 ,
T_2 V_33 , T_2 V_27 , T_2 V_12 , T_2 V_22 ,
struct V_29 * V_30 )
{
int V_42 ;
T_2 V_40 = V_30 -> V_41 ;
bool V_28 = ( V_33 == V_36 ) ;
F_9 ( V_38 , L_12 ) ;
if ( V_30 == NULL )
return - V_25 ;
F_4 ( V_2 , & V_2 -> V_43 ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
V_40 += 3 ;
V_40 &= ( T_2 ) ~ 3 ;
V_42 = F_22 ( V_2 , V_27 , V_28 , V_12 ,
V_22 , V_30 , V_40 ) ;
if ( V_42 ) {
F_9 ( ERROR , L_18 ,
V_27 ? L_14 : L_15 , V_30 , V_22 , V_40 , V_42 ) ;
} else {
F_9 ( V_38 , L_19 ,
V_27 ? L_14 : L_15 , V_30 , V_22 , V_40 ) ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
return V_42 ;
}
static int
F_29 ( struct V_1 * V_2 , int V_12 , T_4 V_8 ,
int V_44 , T_4 * V_32 )
{
if ( ( V_12 == 0 ) || ( V_44 == 1 ) ) {
T_3 V_45 = 0 ;
F_14 ( V_2 , V_46 , V_12 , V_8 ,
& V_45 ) ;
* V_32 = V_45 ;
* V_32 &= 0xff ;
F_9 ( V_47 , L_20 , * V_32 ) ;
} else {
F_17 ( V_2 , V_46 , V_12 , V_8 ,
V_32 , V_44 ) ;
if ( V_44 == 2 )
* V_32 &= 0xffff ;
F_9 ( V_47 , L_21 , * V_32 ) ;
}
return V_48 ;
}
static int F_30 ( struct V_1 * V_2 , T_4 V_8 )
{
int V_49 ;
T_4 V_50 , V_51 ;
T_5 V_52 ;
T_3 * V_53 = ( T_3 * ) & V_52 ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
if ( ( F_29 ( V_2 , 0 , V_8 , 1 ,
& V_51 ) ) != V_48 )
F_9 ( ERROR , L_22 ) ;
* V_53 ++ = ( T_3 ) V_51 ;
V_8 ++ ;
}
V_50 = F_31 ( V_52 ) ;
V_50 &= 0x0001FFFF ;
return V_50 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_13 ;
T_4 V_54 ;
T_3 V_12 ;
F_9 ( V_38 , L_23 ) ;
V_2 -> V_55 [ 0 ] = F_30 ( V_2 ,
V_56 ) ;
F_9 ( V_19 , L_24 ,
V_2 -> V_55 [ 0 ] ) ;
for ( V_54 = F_33 ( 1 ) , V_12 = 1 ;
V_12 <= V_2 -> V_57 ; V_12 ++ , V_54 += V_58 ) {
V_2 -> V_55 [ V_12 ] =
F_30 ( V_2 , V_59 + V_54 ) ;
F_9 ( V_19 , L_25 ,
V_12 , V_2 -> V_55 [ V_12 ] ) ;
}
F_7 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_8 ( V_2 -> V_12 [ 1 ] ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 )
F_9 ( ERROR , L_26 , V_13 ) ;
return false ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_9 ( V_38 , L_23 ) ;
V_2 -> V_57 = 2 ;
F_7 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_35 ( V_2 -> V_12 [ 1 ] , V_60 ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 ) {
F_9 ( ERROR , L_27 ) ;
goto V_61;
}
F_7 ( V_2 -> V_12 [ 2 ] ) ;
V_13 = F_35 ( V_2 -> V_12 [ 2 ] , V_62 ) ;
F_11 ( V_2 -> V_12 [ 2 ] ) ;
if ( V_13 ) {
F_9 ( ERROR , L_28 ) ;
goto V_61;
}
F_32 ( V_2 ) ;
V_61:
F_9 ( V_38 , L_29 ) ;
return V_13 ;
}
void F_36 ( struct V_1 * V_2 )
{
F_9 ( V_38 , L_23 ) ;
F_7 ( V_2 -> V_12 [ 2 ] ) ;
F_10 ( V_2 -> V_12 [ 2 ] ) ;
F_11 ( V_2 -> V_12 [ 2 ] ) ;
F_7 ( V_2 -> V_12 [ 1 ] ) ;
F_10 ( V_2 -> V_12 [ 1 ] ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
}
static int F_37 ( struct V_10 * V_12 ,
const struct V_63 * V_64 )
{
int V_65 = 0 ;
struct V_1 * V_2 ;
struct V_66 * V_67 ;
F_9 ( V_38 , L_12 ) ;
F_9 ( V_38 , L_30 , V_12 -> V_68 ) ;
F_9 ( V_38 , L_31 , V_12 -> V_69 ) ;
F_9 ( V_38 , L_32 , V_12 -> V_70 ) ;
F_9 ( V_38 , L_33 , V_12 -> V_71 ) ;
if ( V_12 -> V_71 == 1 ) {
if ( F_38 ( & V_12 -> V_72 -> V_73 ) ) {
F_9 ( ERROR , L_34 ) ;
return - V_74 ;
}
V_67 = F_39 ( sizeof( struct V_66 ) , V_75 ) ;
if ( ! V_67 )
return - V_76 ;
V_2 = F_39 ( sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_2 ) {
F_40 ( V_67 ) ;
return - V_76 ;
}
V_2 -> V_12 [ 0 ] = V_12 -> V_72 -> V_10 [ 0 ] ;
V_2 -> V_12 [ 1 ] = V_12 ;
V_2 -> V_67 = V_67 ;
V_67 -> V_77 = V_2 ;
V_67 -> type = V_78 ;
V_67 -> V_79 = V_80 ;
F_41 ( & V_12 -> V_72 -> V_73 , V_2 ) ;
F_42 ( & V_2 -> V_4 , false ) ;
F_43 ( & V_2 -> V_20 ) ;
F_43 ( & V_2 -> V_26 ) ;
F_43 ( & V_2 -> V_39 ) ;
F_43 ( & V_2 -> V_43 ) ;
}
if ( V_12 -> V_71 == 2 ) {
V_2 = F_38 ( & V_12 -> V_72 -> V_73 ) ;
if ( ( ! V_2 ) || ( V_2 -> V_12 [ 1 ] -> V_72 != V_12 -> V_72 ) )
return - V_81 ;
V_2 -> V_12 [ 2 ] = V_12 ;
V_67 = V_2 -> V_67 ;
V_2 -> V_73 = & V_12 -> V_73 ;
F_41 ( & V_12 -> V_73 , V_67 ) ;
F_9 ( V_38 , L_35 ) ;
V_65 = F_44 ( V_2 ) ;
}
return V_65 ;
}
static void F_45 ( struct V_10 * V_12 )
{
struct V_66 * V_67 ;
struct V_1 * V_2 ;
F_9 ( V_38 , L_12 ) ;
F_9 ( V_19 , L_30 , V_12 -> V_68 ) ;
F_9 ( V_19 , L_31 , V_12 -> V_69 ) ;
F_9 ( V_19 , L_32 , V_12 -> V_70 ) ;
F_9 ( V_19 , L_33 , V_12 -> V_71 ) ;
if ( V_12 -> V_71 == 2 ) {
V_67 = F_38 ( & V_12 -> V_73 ) ;
V_2 = V_67 -> V_77 ;
F_9 ( V_38 , L_36 ) ;
F_46 ( V_2 ) ;
F_41 ( & V_12 -> V_72 -> V_73 , NULL ) ;
F_41 ( & V_12 -> V_73 , NULL ) ;
F_40 ( V_67 ) ;
F_40 ( V_2 ) ;
}
}
static int F_47 ( struct V_70 * V_73 )
{
T_6 V_82 ;
struct V_10 * V_12 = F_48 ( V_73 ) ;
struct V_1 * V_2 = F_38 ( & V_12 -> V_72 -> V_73 ) ;
int V_65 = 0 ;
F_9 ( V_38 , L_23 ) ;
F_42 ( & V_2 -> V_4 , true ) ;
V_82 = F_49 ( V_2 -> V_12 [ 1 ] ) ;
if ( ! ( V_82 & V_83 ) ) {
F_9 ( ERROR , L_37 ) ;
return - V_25 ;
}
V_65 = F_50 ( V_2 -> V_12 [ 1 ] , V_83 ) ;
if ( V_65 ) {
F_9 ( ERROR , L_38 ) ;
return V_65 ;
}
F_51 ( V_2 , false ) ;
return V_65 ;
}
static int F_52 ( struct V_70 * V_73 )
{
struct V_10 * V_12 = F_48 ( V_73 ) ;
struct V_1 * V_2 = F_38 ( & V_12 -> V_72 -> V_73 ) ;
F_51 ( V_2 , true ) ;
F_42 ( & V_2 -> V_4 , false ) ;
return 0 ;
}
static void T_7 F_53 ( void )
{
F_9 ( V_38 , L_12 ) ;
F_54 ( & V_84 ) ;
}
static int T_8 F_55 ( void )
{
int V_65 ;
F_9 ( V_38 , L_12 ) ;
V_65 = F_56 ( & V_84 ) ;
if ( V_65 )
F_9 ( ERROR , L_39 , V_65 ) ;
return V_65 ;
}
