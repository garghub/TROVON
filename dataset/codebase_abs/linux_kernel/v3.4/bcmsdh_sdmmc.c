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
V_11 = F_12 ( V_2 -> V_12 [ 0 ] , sizeof( struct V_10 ) ,
V_17 ) ;
if ( ! V_11 )
return - V_18 ;
V_11 -> V_19 = 0 ;
F_7 ( V_11 ) ;
F_13 ( V_11 , * V_9 , V_8 , & V_13 ) ;
F_11 ( V_11 ) ;
F_14 ( V_11 ) ;
} else if ( V_8 < 0xF0 ) {
F_9 ( ERROR , L_3 , V_8 ) ;
V_13 = - V_20 ;
} else {
F_7 ( V_11 ) ;
F_15 ( V_11 , * V_9 , V_8 , & V_13 ) ;
F_11 ( V_11 ) ;
}
return V_13 ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_21 , T_2 V_12 ,
T_2 V_8 , T_3 * V_9 )
{
int V_13 ;
F_9 ( V_22 , L_4 , V_21 , V_12 , V_8 ) ;
F_4 ( V_2 , & V_2 -> V_23 ) ;
if ( F_1 ( V_2 ) )
return - V_24 ;
if ( V_21 && V_12 == 0 ) {
V_13 = F_6 ( V_2 , V_8 , V_9 ) ;
} else {
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
if ( V_21 )
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
V_21 ? L_6 : L_7 , V_12 , V_8 , * V_9 , V_13 ) ;
return V_13 ;
}
int F_19 ( struct V_1 * V_2 ,
T_2 V_21 , T_2 V_12 , T_2 V_25 , T_4 * V_26 ,
T_2 V_27 )
{
int V_13 = - V_24 ;
if ( V_12 == 0 ) {
F_9 ( ERROR , L_8 ) ;
return - V_28 ;
}
F_9 ( V_22 , L_9 ,
V_21 , V_12 , V_25 , V_27 ) ;
F_4 ( V_2 , & V_2 -> V_29 ) ;
if ( F_1 ( V_2 ) )
return - V_24 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
if ( V_21 ) {
if ( V_27 == 4 )
F_20 ( V_2 -> V_12 [ V_12 ] , * V_26 , V_25 ,
& V_13 ) ;
else if ( V_27 == 2 )
F_21 ( V_2 -> V_12 [ V_12 ] , ( * V_26 & 0xFFFF ) ,
V_25 , & V_13 ) ;
else
F_9 ( ERROR , L_10 , V_27 ) ;
} else {
if ( V_27 == 4 )
* V_26 = F_22 ( V_2 -> V_12 [ V_12 ] , V_25 , & V_13 ) ;
else if ( V_27 == 2 )
* V_26 = F_23 ( V_2 -> V_12 [ V_12 ] , V_25 ,
& V_13 ) & 0xFFFF ;
else
F_9 ( ERROR , L_10 , V_27 ) ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
if ( V_13 )
F_9 ( ERROR , L_11 ,
V_21 ? L_6 : L_7 , V_13 ) ;
return V_13 ;
}
static int
F_24 ( struct V_1 * V_2 , T_2 V_30 , bool V_31 ,
T_2 V_12 , T_2 V_25 , struct V_32 * V_33 , T_2 V_34 )
{
int V_13 = 0 ;
if ( ( V_30 ) && ( ! V_31 ) ) {
V_13 = F_25 ( V_2 -> V_12 [ V_12 ] , V_25 ,
( ( T_3 * ) ( V_33 -> V_35 ) ) , V_34 ) ;
} else if ( V_30 ) {
V_13 = F_25 ( V_2 -> V_12 [ V_12 ] , V_25 ,
( ( T_3 * ) ( V_33 -> V_35 ) ) , V_34 ) ;
} else if ( V_31 ) {
V_13 = F_26 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_33 -> V_35 ) ) , V_25 , V_34 ) ;
} else {
V_13 = F_27 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_33 -> V_35 ) ) ,
V_25 , V_34 ) ;
}
return V_13 ;
}
int
F_28 ( struct V_1 * V_2 , T_2 V_36 ,
T_2 V_30 , T_2 V_12 , T_2 V_25 ,
struct V_37 * V_38 )
{
bool V_31 = ( V_36 == V_39 ) ;
T_4 V_40 = 0 ;
int V_13 = 0 ;
struct V_32 * V_33 ;
F_9 ( V_41 , L_12 ) ;
F_4 ( V_2 , & V_2 -> V_42 ) ;
if ( F_1 ( V_2 ) )
return - V_24 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
F_29 (pktq, pkt) {
T_2 V_43 = V_33 -> V_44 ;
V_43 += 3 ;
V_43 &= 0xFFFFFFFC ;
V_13 = F_24 ( V_2 , V_30 , V_31 , V_12 ,
V_25 , V_33 , V_43 ) ;
if ( V_13 ) {
F_9 ( ERROR , L_13 ,
V_30 ? L_14 : L_15 , V_33 , V_40 , V_25 ,
V_43 , V_13 ) ;
} else {
F_9 ( V_41 , L_16 ,
V_30 ? L_14 : L_15 , V_33 , V_40 , V_25 ,
V_43 ) ;
}
if ( ! V_31 )
V_25 += V_43 ;
V_40 ++ ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
F_9 ( V_41 , L_17 ) ;
return V_13 ;
}
int F_30 ( struct V_1 * V_2 ,
T_2 V_36 , T_2 V_30 , T_2 V_12 , T_2 V_25 ,
struct V_32 * V_33 )
{
int V_45 ;
T_2 V_43 ;
bool V_31 = ( V_36 == V_39 ) ;
F_9 ( V_41 , L_12 ) ;
if ( V_33 == NULL )
return - V_28 ;
V_43 = V_33 -> V_44 ;
F_4 ( V_2 , & V_2 -> V_46 ) ;
if ( F_1 ( V_2 ) )
return - V_24 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
V_43 += 3 ;
V_43 &= ( T_2 ) ~ 3 ;
V_45 = F_24 ( V_2 , V_30 , V_31 , V_12 ,
V_25 , V_33 , V_43 ) ;
if ( V_45 ) {
F_9 ( ERROR , L_18 ,
V_30 ? L_14 : L_15 , V_33 , V_25 , V_43 , V_45 ) ;
} else {
F_9 ( V_41 , L_19 ,
V_30 ? L_14 : L_15 , V_33 , V_25 , V_43 ) ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
return V_45 ;
}
static int
F_31 ( struct V_1 * V_2 , int V_12 , T_4 V_8 ,
int V_47 , T_4 * V_35 )
{
if ( ( V_12 == 0 ) || ( V_47 == 1 ) ) {
T_3 V_48 = 0 ;
F_16 ( V_2 , V_49 , V_12 , V_8 ,
& V_48 ) ;
* V_35 = V_48 ;
* V_35 &= 0xff ;
F_9 ( V_50 , L_20 , * V_35 ) ;
} else {
F_19 ( V_2 , V_49 , V_12 , V_8 ,
V_35 , V_47 ) ;
if ( V_47 == 2 )
* V_35 &= 0xffff ;
F_9 ( V_50 , L_21 , * V_35 ) ;
}
return V_51 ;
}
static int F_32 ( struct V_1 * V_2 , T_4 V_8 )
{
int V_52 ;
T_4 V_53 , V_54 ;
T_5 V_55 ;
T_3 * V_56 = ( T_3 * ) & V_55 ;
for ( V_52 = 0 ; V_52 < 3 ; V_52 ++ ) {
if ( ( F_31 ( V_2 , 0 , V_8 , 1 ,
& V_54 ) ) != V_51 )
F_9 ( ERROR , L_22 ) ;
* V_56 ++ = ( T_3 ) V_54 ;
V_8 ++ ;
}
V_53 = F_33 ( V_55 ) ;
V_53 &= 0x0001FFFF ;
return V_53 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_13 ;
T_4 V_57 ;
T_3 V_12 ;
F_9 ( V_41 , L_23 ) ;
V_2 -> V_58 [ 0 ] = F_32 ( V_2 ,
V_59 ) ;
F_9 ( V_22 , L_24 ,
V_2 -> V_58 [ 0 ] ) ;
for ( V_57 = F_35 ( 1 ) , V_12 = 1 ;
V_12 <= V_2 -> V_60 ; V_12 ++ , V_57 += V_61 ) {
V_2 -> V_58 [ V_12 ] =
F_32 ( V_2 , V_62 + V_57 ) ;
F_9 ( V_22 , L_25 ,
V_12 , V_2 -> V_58 [ V_12 ] ) ;
}
F_7 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_8 ( V_2 -> V_12 [ 1 ] ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 )
F_9 ( ERROR , L_26 , V_13 ) ;
return false ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_9 ( V_41 , L_23 ) ;
V_2 -> V_60 = 2 ;
F_7 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_37 ( V_2 -> V_12 [ 1 ] , V_63 ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 ) {
F_9 ( ERROR , L_27 ) ;
goto V_64;
}
F_7 ( V_2 -> V_12 [ 2 ] ) ;
V_13 = F_37 ( V_2 -> V_12 [ 2 ] , V_65 ) ;
F_11 ( V_2 -> V_12 [ 2 ] ) ;
if ( V_13 ) {
F_9 ( ERROR , L_28 ) ;
goto V_64;
}
F_34 ( V_2 ) ;
V_64:
F_9 ( V_41 , L_29 ) ;
return V_13 ;
}
void F_38 ( struct V_1 * V_2 )
{
F_9 ( V_41 , L_23 ) ;
F_7 ( V_2 -> V_12 [ 2 ] ) ;
F_10 ( V_2 -> V_12 [ 2 ] ) ;
F_11 ( V_2 -> V_12 [ 2 ] ) ;
F_7 ( V_2 -> V_12 [ 1 ] ) ;
F_10 ( V_2 -> V_12 [ 1 ] ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
}
static int F_39 ( struct V_10 * V_12 ,
const struct V_66 * V_67 )
{
int V_68 = 0 ;
struct V_1 * V_2 ;
struct V_69 * V_70 ;
F_9 ( V_41 , L_12 ) ;
F_9 ( V_41 , L_30 , V_12 -> V_71 ) ;
F_9 ( V_41 , L_31 , V_12 -> V_72 ) ;
F_9 ( V_41 , L_32 , V_12 -> V_73 ) ;
F_9 ( V_41 , L_33 , V_12 -> V_19 ) ;
if ( V_12 -> V_19 == 1 ) {
if ( F_40 ( & V_12 -> V_74 -> V_75 ) ) {
F_9 ( ERROR , L_34 ) ;
return - V_76 ;
}
V_70 = F_41 ( sizeof( struct V_69 ) , V_17 ) ;
if ( ! V_70 )
return - V_18 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_17 ) ;
if ( ! V_2 ) {
F_14 ( V_70 ) ;
return - V_18 ;
}
V_2 -> V_12 [ 0 ] = V_12 ;
V_2 -> V_12 [ 1 ] = V_12 ;
V_2 -> V_70 = V_70 ;
V_70 -> V_77 . V_78 = V_2 ;
V_70 -> type = V_79 ;
V_70 -> V_80 = V_81 ;
F_42 ( & V_12 -> V_74 -> V_75 , V_2 ) ;
F_43 ( & V_2 -> V_4 , false ) ;
F_44 ( & V_2 -> V_23 ) ;
F_44 ( & V_2 -> V_29 ) ;
F_44 ( & V_2 -> V_42 ) ;
F_44 ( & V_2 -> V_46 ) ;
}
if ( V_12 -> V_19 == 2 ) {
V_2 = F_40 ( & V_12 -> V_74 -> V_75 ) ;
if ( ( ! V_2 ) || ( V_2 -> V_12 [ 1 ] -> V_74 != V_12 -> V_74 ) )
return - V_82 ;
V_2 -> V_12 [ 2 ] = V_12 ;
V_70 = V_2 -> V_70 ;
V_2 -> V_75 = & V_12 -> V_75 ;
F_42 ( & V_12 -> V_75 , V_70 ) ;
F_9 ( V_41 , L_35 ) ;
V_68 = F_45 ( V_2 ) ;
}
return V_68 ;
}
static void F_46 ( struct V_10 * V_12 )
{
struct V_69 * V_70 ;
struct V_1 * V_2 ;
F_9 ( V_41 , L_12 ) ;
F_9 ( V_22 , L_30 , V_12 -> V_71 ) ;
F_9 ( V_22 , L_31 , V_12 -> V_72 ) ;
F_9 ( V_22 , L_32 , V_12 -> V_73 ) ;
F_9 ( V_22 , L_33 , V_12 -> V_19 ) ;
if ( V_12 -> V_19 == 2 ) {
V_70 = F_40 ( & V_12 -> V_75 ) ;
V_2 = V_70 -> V_77 . V_78 ;
F_9 ( V_41 , L_36 ) ;
F_47 ( V_2 ) ;
F_42 ( & V_12 -> V_74 -> V_75 , NULL ) ;
F_42 ( & V_12 -> V_75 , NULL ) ;
F_14 ( V_70 ) ;
F_14 ( V_2 ) ;
}
}
static int F_48 ( struct V_73 * V_75 )
{
T_6 V_83 ;
struct V_10 * V_12 = F_49 ( V_75 ) ;
struct V_1 * V_2 = F_40 ( & V_12 -> V_74 -> V_75 ) ;
int V_68 = 0 ;
F_9 ( V_41 , L_23 ) ;
F_43 ( & V_2 -> V_4 , true ) ;
V_83 = F_50 ( V_2 -> V_12 [ 1 ] ) ;
if ( ! ( V_83 & V_84 ) ) {
F_9 ( ERROR , L_37 ) ;
return - V_28 ;
}
V_68 = F_51 ( V_2 -> V_12 [ 1 ] , V_84 ) ;
if ( V_68 ) {
F_9 ( ERROR , L_38 ) ;
return V_68 ;
}
F_52 ( V_2 , false ) ;
return V_68 ;
}
static int F_53 ( struct V_73 * V_75 )
{
struct V_10 * V_12 = F_49 ( V_75 ) ;
struct V_1 * V_2 = F_40 ( & V_12 -> V_74 -> V_75 ) ;
F_52 ( V_2 , true ) ;
F_43 ( & V_2 -> V_4 , false ) ;
return 0 ;
}
void F_54 ( void )
{
F_9 ( V_41 , L_12 ) ;
F_55 ( & V_85 ) ;
}
void F_56 ( void )
{
int V_68 ;
F_9 ( V_41 , L_12 ) ;
V_68 = F_57 ( & V_85 ) ;
if ( V_68 )
F_9 ( ERROR , L_39 , V_68 ) ;
}
