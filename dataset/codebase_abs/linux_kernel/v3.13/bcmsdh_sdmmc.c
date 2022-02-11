bool
F_1 ( struct V_1 * V_2 )
{
bool V_3 = false ;
#ifdef F_2
V_3 = F_3 ( & V_2 -> V_4 ) ;
#endif
return V_3 ;
}
void
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
} else {
V_13 = - V_16 ;
}
} else if ( ( V_8 == V_17 ) ||
( V_8 == V_18 ) ) {
V_11 = F_10 ( V_2 -> V_12 [ 0 ] , sizeof( struct V_10 ) ,
V_19 ) ;
if ( ! V_11 )
return - V_20 ;
V_11 -> V_21 = 0 ;
F_11 ( V_11 , * V_9 , V_8 , & V_13 ) ;
F_12 ( V_11 ) ;
} else if ( V_8 < 0xF0 ) {
F_8 ( L_3 , V_8 ) ;
V_13 = - V_22 ;
} else {
F_13 ( V_11 , * V_9 , V_8 , & V_13 ) ;
}
return V_13 ;
}
int F_14 ( struct V_1 * V_2 , T_2 V_23 , T_2 V_12 ,
T_2 V_8 , T_3 * V_9 )
{
int V_13 ;
F_15 ( V_24 , L_4 , V_23 , V_12 , V_8 ) ;
F_4 ( V_2 , & V_2 -> V_25 ) ;
if ( F_1 ( V_2 ) )
return - V_26 ;
if ( V_23 && V_12 == 0 ) {
V_13 = F_6 ( V_2 , V_8 , V_9 ) ;
} else {
if ( V_23 )
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
V_23 ? L_6 : L_7 , V_12 , V_8 , * V_9 , V_13 ) ;
return V_13 ;
}
int F_18 ( struct V_1 * V_2 ,
T_2 V_23 , T_2 V_12 , T_2 V_27 , T_4 * V_28 ,
T_2 V_29 )
{
int V_13 = - V_26 ;
if ( V_12 == 0 ) {
F_8 ( L_8 ) ;
return - V_30 ;
}
F_15 ( V_24 , L_9 ,
V_23 , V_12 , V_27 , V_29 ) ;
F_4 ( V_2 , & V_2 -> V_31 ) ;
if ( F_1 ( V_2 ) )
return - V_26 ;
if ( V_23 ) {
if ( V_29 == 4 )
F_19 ( V_2 -> V_12 [ V_12 ] , * V_28 , V_27 ,
& V_13 ) ;
else if ( V_29 == 2 )
F_20 ( V_2 -> V_12 [ V_12 ] , ( * V_28 & 0xFFFF ) ,
V_27 , & V_13 ) ;
else
F_8 ( L_10 , V_29 ) ;
} else {
if ( V_29 == 4 )
* V_28 = F_21 ( V_2 -> V_12 [ V_12 ] , V_27 , & V_13 ) ;
else if ( V_29 == 2 )
* V_28 = F_22 ( V_2 -> V_12 [ V_12 ] , V_27 ,
& V_13 ) & 0xFFFF ;
else
F_8 ( L_10 , V_29 ) ;
}
if ( V_13 )
F_8 ( L_11 ,
V_23 ? L_6 : L_7 , V_13 ) ;
return V_13 ;
}
static int F_23 ( struct V_1 * V_2 , T_4 V_8 )
{
int V_32 , V_33 ;
T_4 V_34 , V_35 ;
T_5 V_36 ;
T_3 * V_37 = ( T_3 * ) & V_36 ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
V_35 = F_24 ( V_2 , V_8 , & V_33 ) ;
if ( V_33 != 0 )
F_8 ( L_12 ) ;
* V_37 ++ = ( T_3 ) V_35 ;
V_8 ++ ;
}
V_34 = F_25 ( V_36 ) ;
V_34 &= 0x0001FFFF ;
return V_34 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_13 ;
T_4 V_38 ;
T_3 V_12 ;
F_15 ( V_24 , L_13 ) ;
V_2 -> V_39 [ 0 ] = F_23 ( V_2 ,
V_40 ) ;
F_15 ( V_24 , L_14 ,
V_2 -> V_39 [ 0 ] ) ;
for ( V_38 = F_27 ( 1 ) , V_12 = 1 ;
V_12 <= V_2 -> V_41 ; V_12 ++ , V_38 += V_42 ) {
V_2 -> V_39 [ V_12 ] =
F_23 ( V_2 , V_43 + V_38 ) ;
F_15 ( V_24 , L_15 ,
V_12 , V_2 -> V_39 [ V_12 ] ) ;
}
V_13 = F_7 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 )
F_8 ( L_16 , V_13 ) ;
return false ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_15 ( V_24 , L_13 ) ;
V_2 -> V_41 = 2 ;
F_29 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_30 ( V_2 -> V_12 [ 1 ] , V_44 ) ;
if ( V_13 ) {
F_8 ( L_17 ) ;
goto V_45;
}
V_13 = F_30 ( V_2 -> V_12 [ 2 ] , V_46 ) ;
if ( V_13 ) {
F_8 ( L_18 ) ;
goto V_45;
}
F_26 ( V_2 ) ;
V_45:
F_31 ( V_2 -> V_12 [ 1 ] ) ;
F_15 ( V_24 , L_19 ) ;
return V_13 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_15 ( V_24 , L_13 ) ;
F_29 ( V_2 -> V_12 [ 2 ] ) ;
F_9 ( V_2 -> V_12 [ 2 ] ) ;
F_31 ( V_2 -> V_12 [ 2 ] ) ;
F_29 ( V_2 -> V_12 [ 1 ] ) ;
F_9 ( V_2 -> V_12 [ 1 ] ) ;
F_31 ( V_2 -> V_12 [ 1 ] ) ;
}
static int F_33 ( struct V_10 * V_12 ,
const struct V_47 * V_48 )
{
int V_49 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
T_2 V_54 ;
F_15 ( V_24 , L_20 ) ;
F_15 ( V_24 , L_21 , V_12 -> V_55 ) ;
F_15 ( V_24 , L_22 , V_12 -> V_56 ) ;
F_15 ( V_24 , L_23 , V_12 -> V_57 ) ;
F_15 ( V_24 , L_24 , V_12 -> V_21 ) ;
if ( V_12 -> V_21 == 1 )
return 0 ;
if ( V_12 -> V_21 != 2 )
return - V_58 ;
V_51 = F_34 ( sizeof( struct V_50 ) , V_19 ) ;
if ( ! V_51 )
return - V_20 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_2 ) {
F_12 ( V_51 ) ;
return - V_20 ;
}
V_2 -> V_12 [ 0 ] = V_12 -> V_59 -> V_10 [ 0 ] ;
V_2 -> V_12 [ 1 ] = V_12 -> V_59 -> V_10 [ 0 ] ;
V_2 -> V_12 [ 2 ] = V_12 ;
V_2 -> V_51 = V_51 ;
V_51 -> V_60 . V_61 = V_2 ;
F_35 ( & V_12 -> V_62 , V_51 ) ;
F_35 ( & V_2 -> V_12 [ 1 ] -> V_62 , V_51 ) ;
V_2 -> V_62 = & V_2 -> V_12 [ 1 ] -> V_62 ;
V_2 -> V_63 = V_64 ;
F_36 ( & V_2 -> V_4 , false ) ;
F_37 ( & V_2 -> V_25 ) ;
F_37 ( & V_2 -> V_31 ) ;
F_37 ( & V_2 -> V_65 ) ;
F_15 ( V_24 , L_25 ) ;
V_49 = F_38 ( V_2 ) ;
if ( V_49 ) {
F_8 ( L_26 , V_49 ) ;
goto V_66;
}
V_53 = V_12 -> V_59 -> V_53 ;
V_2 -> V_67 = V_53 -> V_68 > 1 ;
V_54 = F_39 ( T_2 , V_53 -> V_69 , 511u ) ;
V_2 -> V_70 = F_39 ( T_2 , V_53 -> V_71 ,
V_54 * V_12 -> V_72 ) ;
V_2 -> V_73 = F_39 ( T_2 , V_53 -> V_68 ,
V_74 ) ;
V_2 -> V_75 = V_53 -> V_76 ;
F_15 ( V_24 , L_27 ) ;
return 0 ;
V_66:
F_35 ( & V_12 -> V_62 , NULL ) ;
F_35 ( & V_2 -> V_12 [ 1 ] -> V_62 , NULL ) ;
F_12 ( V_2 ) ;
F_12 ( V_51 ) ;
return V_49 ;
}
static void F_40 ( struct V_10 * V_12 )
{
struct V_50 * V_51 ;
struct V_1 * V_2 ;
F_15 ( V_24 , L_20 ) ;
F_15 ( V_24 , L_22 , V_12 -> V_56 ) ;
F_15 ( V_24 , L_23 , V_12 -> V_57 ) ;
F_15 ( V_24 , L_28 , V_12 -> V_21 ) ;
if ( V_12 -> V_21 != 1 && V_12 -> V_21 != 2 )
return;
V_51 = F_41 ( & V_12 -> V_62 ) ;
if ( V_51 ) {
V_2 = V_51 -> V_60 . V_61 ;
F_42 ( V_2 ) ;
F_35 ( & V_2 -> V_12 [ 1 ] -> V_62 , NULL ) ;
F_35 ( & V_2 -> V_12 [ 2 ] -> V_62 , NULL ) ;
F_12 ( V_51 ) ;
F_12 ( V_2 ) ;
}
F_15 ( V_24 , L_29 ) ;
}
static int F_43 ( struct V_57 * V_62 )
{
T_6 V_77 ;
struct V_50 * V_51 = F_41 ( V_62 ) ;
struct V_1 * V_2 = V_51 -> V_60 . V_61 ;
int V_33 = 0 ;
F_15 ( V_24 , L_13 ) ;
F_36 ( & V_2 -> V_4 , true ) ;
V_77 = F_44 ( V_2 -> V_12 [ 1 ] ) ;
if ( ! ( V_77 & V_78 ) ) {
F_8 ( L_30 ) ;
return - V_30 ;
}
V_33 = F_45 ( V_2 -> V_12 [ 1 ] , V_78 ) ;
if ( V_33 ) {
F_8 ( L_31 ) ;
return V_33 ;
}
F_46 ( V_2 , false ) ;
return V_33 ;
}
static int F_47 ( struct V_57 * V_62 )
{
struct V_50 * V_51 = F_41 ( V_62 ) ;
struct V_1 * V_2 = V_51 -> V_60 . V_61 ;
F_46 ( V_2 , true ) ;
F_36 ( & V_2 -> V_4 , false ) ;
return 0 ;
}
static int F_48 ( struct V_79 * V_80 )
{
F_15 ( V_24 , L_20 ) ;
V_64 = F_49 ( & V_80 -> V_62 ) ;
if ( V_64 -> V_81 )
V_64 -> V_81 () ;
return 0 ;
}
static int F_50 ( struct V_79 * V_80 )
{
F_15 ( V_24 , L_20 ) ;
if ( V_64 -> V_82 )
V_64 -> V_82 () ;
F_51 ( & V_83 ) ;
return 0 ;
}
void F_52 ( void )
{
int V_33 ;
V_33 = F_53 ( & V_83 ) ;
if ( V_33 )
F_8 ( L_32 , V_33 ) ;
}
void F_54 ( void )
{
F_15 ( V_24 , L_20 ) ;
if ( V_64 )
F_55 ( & V_84 ) ;
else
F_51 ( & V_83 ) ;
}
void T_7 F_56 ( void )
{
int V_33 ;
F_15 ( V_24 , L_20 ) ;
V_33 = F_57 ( & V_84 , F_48 ) ;
if ( V_33 == - V_58 )
F_15 ( V_24 , L_33 ) ;
}
