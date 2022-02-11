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
F_22 ( struct V_1 * V_2 , T_2 V_27 ,
T_2 V_28 , T_2 V_12 , T_2 V_22 ,
struct V_29 * V_30 )
{
bool V_31 = ( V_27 == V_32 ) ;
T_4 V_33 = 0 ;
int V_13 = 0 ;
struct V_29 * V_34 ;
F_9 ( V_35 , L_12 ) ;
F_4 ( V_2 , & V_2 -> V_36 ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
F_7 ( V_2 -> V_12 [ V_12 ] ) ;
for ( V_34 = V_30 ; V_34 ; V_34 = V_34 -> V_37 ) {
T_2 V_38 = V_34 -> V_39 ;
V_38 += 3 ;
V_38 &= 0xFFFFFFFC ;
if ( ( V_28 ) && ( ! V_31 ) ) {
V_13 = F_23 ( V_2 -> V_12 [ V_12 ] , V_22 ,
( ( T_3 * ) ( V_34 -> V_40 ) ) ,
V_38 ) ;
} else if ( V_28 ) {
V_13 = F_23 ( V_2 -> V_12 [ V_12 ] , V_22 ,
( ( T_3 * ) ( V_34 -> V_40 ) ) ,
V_38 ) ;
} else if ( V_31 ) {
V_13 = F_24 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_34 -> V_40 ) ) ,
V_22 , V_38 ) ;
} else {
V_13 = F_25 ( V_2 -> V_12 [ V_12 ] ,
( ( T_3 * ) ( V_34 -> V_40 ) ) ,
V_22 , V_38 ) ;
}
if ( V_13 ) {
F_9 ( ERROR , L_13 ,
V_28 ? L_14 : L_15 , V_34 , V_33 , V_22 ,
V_38 , V_13 ) ;
} else {
F_9 ( V_35 , L_16 ,
V_28 ? L_14 : L_15 , V_34 , V_33 , V_22 ,
V_38 ) ;
}
if ( ! V_31 )
V_22 += V_38 ;
V_33 ++ ;
}
F_11 ( V_2 -> V_12 [ V_12 ] ) ;
F_9 ( V_35 , L_17 ) ;
return V_13 ;
}
int F_26 ( struct V_1 * V_2 ,
T_2 V_27 , T_2 V_28 , T_2 V_12 , T_2 V_22 ,
T_2 V_41 , T_2 V_42 , T_3 * V_43 ,
struct V_29 * V_30 )
{
int V_44 ;
struct V_29 * V_45 = NULL ;
F_9 ( V_35 , L_12 ) ;
F_4 ( V_2 , & V_2 -> V_46 ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
if ( V_30 == NULL ) {
F_9 ( V_47 , L_18 ,
V_28 ? L_14 : L_15 , V_42 ) ;
V_45 = F_27 ( V_42 ) ;
if ( ! V_45 ) {
F_9 ( ERROR , L_19 ,
V_42 ) ;
return - V_21 ;
}
if ( V_28 )
memcpy ( V_45 -> V_40 , V_43 , V_42 ) ;
V_44 = F_22 ( V_2 , V_27 , V_28 ,
V_12 , V_22 , V_45 ) ;
if ( ! V_28 )
memcpy ( V_43 , V_45 -> V_40 , V_42 ) ;
F_28 ( V_45 ) ;
} else if ( ( ( V_48 ) ( V_30 -> V_40 ) & V_49 ) != 0 ) {
F_9 ( V_47 , L_20 ,
V_28 ? L_14 : L_15 , V_30 -> V_39 ) ;
V_45 = F_27 ( V_30 -> V_39 ) ;
if ( ! V_45 ) {
F_9 ( ERROR , L_19 ,
V_30 -> V_39 ) ;
return - V_21 ;
}
if ( V_28 )
memcpy ( V_45 -> V_40 , V_30 -> V_40 , V_30 -> V_39 ) ;
V_44 = F_22 ( V_2 , V_27 , V_28 ,
V_12 , V_22 , V_45 ) ;
if ( ! V_28 )
memcpy ( V_30 -> V_40 , V_45 -> V_40 , V_45 -> V_39 ) ;
F_28 ( V_45 ) ;
} else {
F_9 ( V_47 , L_21 ,
V_28 ? L_22 : L_23 ) ;
V_44 = F_22 ( V_2 , V_27 , V_28 ,
V_12 , V_22 , V_30 ) ;
}
return V_44 ;
}
static int
F_29 ( struct V_1 * V_2 , int V_12 , T_4 V_8 ,
int V_50 , T_4 * V_40 )
{
if ( ( V_12 == 0 ) || ( V_50 == 1 ) ) {
T_3 V_51 = 0 ;
F_14 ( V_2 , V_52 , V_12 , V_8 ,
& V_51 ) ;
* V_40 = V_51 ;
* V_40 &= 0xff ;
F_9 ( V_47 , L_24 , * V_40 ) ;
} else {
F_17 ( V_2 , V_52 , V_12 , V_8 ,
V_40 , V_50 ) ;
if ( V_50 == 2 )
* V_40 &= 0xffff ;
F_9 ( V_47 , L_25 , * V_40 ) ;
}
return V_53 ;
}
static int F_30 ( struct V_1 * V_2 , T_4 V_8 )
{
int V_54 ;
T_4 V_55 , V_56 ;
T_5 V_57 ;
T_3 * V_58 = ( T_3 * ) & V_57 ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
if ( ( F_29 ( V_2 , 0 , V_8 , 1 ,
& V_56 ) ) != V_53 )
F_9 ( ERROR , L_26 ) ;
* V_58 ++ = ( T_3 ) V_56 ;
V_8 ++ ;
}
V_55 = F_31 ( V_57 ) ;
V_55 &= 0x0001FFFF ;
return V_55 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_13 ;
T_4 V_59 ;
T_3 V_12 ;
F_9 ( V_35 , L_27 ) ;
V_2 -> V_60 [ 0 ] = F_30 ( V_2 ,
V_61 ) ;
F_9 ( V_19 , L_28 ,
V_2 -> V_60 [ 0 ] ) ;
for ( V_59 = F_33 ( 1 ) , V_12 = 1 ;
V_12 <= V_2 -> V_62 ; V_12 ++ , V_59 += V_63 ) {
V_2 -> V_60 [ V_12 ] =
F_30 ( V_2 , V_64 + V_59 ) ;
F_9 ( V_19 , L_29 ,
V_12 , V_2 -> V_60 [ V_12 ] ) ;
}
F_7 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_8 ( V_2 -> V_12 [ 1 ] ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 )
F_9 ( ERROR , L_30 , V_13 ) ;
return false ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_9 ( V_35 , L_27 ) ;
V_2 -> V_62 = 2 ;
F_7 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_35 ( V_2 -> V_12 [ 1 ] , V_65 ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 ) {
F_9 ( ERROR , L_31 ) ;
goto V_66;
}
F_7 ( V_2 -> V_12 [ 2 ] ) ;
V_13 = F_35 ( V_2 -> V_12 [ 2 ] , V_67 ) ;
F_11 ( V_2 -> V_12 [ 2 ] ) ;
if ( V_13 ) {
F_9 ( ERROR , L_32 ) ;
goto V_66;
}
F_32 ( V_2 ) ;
V_66:
F_9 ( V_35 , L_33 ) ;
return V_13 ;
}
void F_36 ( struct V_1 * V_2 )
{
F_9 ( V_35 , L_27 ) ;
F_7 ( V_2 -> V_12 [ 2 ] ) ;
F_10 ( V_2 -> V_12 [ 2 ] ) ;
F_11 ( V_2 -> V_12 [ 2 ] ) ;
F_7 ( V_2 -> V_12 [ 1 ] ) ;
F_10 ( V_2 -> V_12 [ 1 ] ) ;
F_11 ( V_2 -> V_12 [ 1 ] ) ;
}
static int F_37 ( struct V_10 * V_12 ,
const struct V_68 * V_69 )
{
int V_70 = 0 ;
struct V_1 * V_2 ;
F_9 ( V_35 , L_12 ) ;
F_9 ( V_35 , L_34 , V_12 -> V_71 ) ;
F_9 ( V_35 , L_35 , V_12 -> V_72 ) ;
F_9 ( V_35 , L_36 , V_12 -> V_73 ) ;
F_9 ( V_35 , L_37 , V_12 -> V_74 ) ;
if ( V_12 -> V_74 == 1 ) {
if ( F_38 ( & V_12 -> V_75 -> V_76 ) ) {
F_9 ( ERROR , L_38 ) ;
return - V_77 ;
}
V_2 = F_39 ( sizeof( struct V_1 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
V_2 -> V_12 [ 0 ] = V_12 -> V_75 -> V_10 [ 0 ] ;
V_2 -> V_12 [ 1 ] = V_12 ;
F_40 ( & V_12 -> V_75 -> V_76 , V_2 ) ;
F_41 ( & V_2 -> V_4 , false ) ;
F_42 ( & V_2 -> V_20 ) ;
F_42 ( & V_2 -> V_26 ) ;
F_42 ( & V_2 -> V_36 ) ;
F_42 ( & V_2 -> V_46 ) ;
}
if ( V_12 -> V_74 == 2 ) {
V_2 = F_38 ( & V_12 -> V_75 -> V_76 ) ;
if ( ( ! V_2 ) || ( V_2 -> V_12 [ 1 ] -> V_75 != V_12 -> V_75 ) )
return - V_80 ;
V_2 -> V_12 [ 2 ] = V_12 ;
F_9 ( V_35 , L_39 ) ;
V_70 = F_43 ( V_2 ) ;
}
return V_70 ;
}
static void F_44 ( struct V_10 * V_12 )
{
struct V_1 * V_2 ;
F_9 ( V_35 , L_12 ) ;
F_9 ( V_19 , L_34 , V_12 -> V_71 ) ;
F_9 ( V_19 , L_35 , V_12 -> V_72 ) ;
F_9 ( V_19 , L_36 , V_12 -> V_73 ) ;
F_9 ( V_19 , L_37 , V_12 -> V_74 ) ;
if ( V_12 -> V_74 == 2 ) {
V_2 = F_38 ( & V_12 -> V_75 -> V_76 ) ;
F_9 ( V_35 , L_40 ) ;
F_45 ( V_2 ) ;
F_40 ( & V_12 -> V_75 -> V_76 , NULL ) ;
F_46 ( V_2 ) ;
}
}
static int F_47 ( struct V_73 * V_76 )
{
T_6 V_81 ;
struct V_1 * V_2 ;
struct V_10 * V_12 = F_48 ( V_76 ) ;
int V_70 = 0 ;
F_9 ( V_35 , L_27 ) ;
V_2 = F_38 ( & V_12 -> V_75 -> V_76 ) ;
F_41 ( & V_2 -> V_4 , true ) ;
V_81 = F_49 ( V_2 -> V_12 [ 1 ] ) ;
if ( ! ( V_81 & V_82 ) ) {
F_9 ( ERROR , L_41 ) ;
return - V_25 ;
}
V_70 = F_50 ( V_2 -> V_12 [ 1 ] , V_82 ) ;
if ( V_70 ) {
F_9 ( ERROR , L_42 ) ;
return V_70 ;
}
F_51 ( V_2 , false ) ;
return V_70 ;
}
static int F_52 ( struct V_73 * V_76 )
{
struct V_1 * V_2 ;
struct V_10 * V_12 = F_48 ( V_76 ) ;
V_2 = F_38 ( & V_12 -> V_75 -> V_76 ) ;
F_51 ( V_2 , true ) ;
F_41 ( & V_2 -> V_4 , false ) ;
return 0 ;
}
int F_53 ( void )
{
F_9 ( V_35 , L_12 ) ;
return F_54 ( & V_83 ) ;
}
void F_55 ( void )
{
F_9 ( V_35 , L_12 ) ;
F_56 ( & V_83 ) ;
}
