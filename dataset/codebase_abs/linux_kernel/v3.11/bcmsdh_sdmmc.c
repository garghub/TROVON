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
static int F_23 ( struct V_1 * V_2 , T_4 V_8 )
{
int V_31 , V_32 ;
T_4 V_33 , V_34 ;
T_5 V_35 ;
T_3 * V_36 = ( T_3 * ) & V_35 ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
V_34 = F_24 ( V_2 , V_8 , & V_32 ) ;
if ( V_32 != 0 )
F_8 ( L_12 ) ;
* V_36 ++ = ( T_3 ) V_34 ;
V_8 ++ ;
}
V_33 = F_25 ( V_35 ) ;
V_33 &= 0x0001FFFF ;
return V_33 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_13 ;
T_4 V_37 ;
T_3 V_12 ;
F_15 ( V_23 , L_13 ) ;
V_2 -> V_38 [ 0 ] = F_23 ( V_2 ,
V_39 ) ;
F_15 ( V_23 , L_14 ,
V_2 -> V_38 [ 0 ] ) ;
for ( V_37 = F_27 ( 1 ) , V_12 = 1 ;
V_12 <= V_2 -> V_40 ; V_12 ++ , V_37 += V_41 ) {
V_2 -> V_38 [ V_12 ] =
F_23 ( V_2 , V_42 + V_37 ) ;
F_15 ( V_23 , L_15 ,
V_12 , V_2 -> V_38 [ V_12 ] ) ;
}
V_13 = F_7 ( V_2 -> V_12 [ 1 ] ) ;
if ( V_13 )
F_8 ( L_16 , V_13 ) ;
return false ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_15 ( V_23 , L_13 ) ;
V_2 -> V_40 = 2 ;
F_29 ( V_2 -> V_12 [ 1 ] ) ;
V_13 = F_30 ( V_2 -> V_12 [ 1 ] , V_43 ) ;
if ( V_13 ) {
F_8 ( L_17 ) ;
goto V_44;
}
V_13 = F_30 ( V_2 -> V_12 [ 2 ] , V_45 ) ;
if ( V_13 ) {
F_8 ( L_18 ) ;
goto V_44;
}
F_26 ( V_2 ) ;
V_44:
F_31 ( V_2 -> V_12 [ 1 ] ) ;
F_15 ( V_23 , L_19 ) ;
return V_13 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_15 ( V_23 , L_13 ) ;
F_29 ( V_2 -> V_12 [ 2 ] ) ;
F_9 ( V_2 -> V_12 [ 2 ] ) ;
F_31 ( V_2 -> V_12 [ 2 ] ) ;
F_29 ( V_2 -> V_12 [ 1 ] ) ;
F_9 ( V_2 -> V_12 [ 1 ] ) ;
F_31 ( V_2 -> V_12 [ 1 ] ) ;
}
static int F_33 ( struct V_10 * V_12 ,
const struct V_46 * V_47 )
{
int V_48 ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
F_15 ( V_23 , L_20 ) ;
F_15 ( V_23 , L_21 , V_12 -> V_51 ) ;
F_15 ( V_23 , L_22 , V_12 -> V_52 ) ;
F_15 ( V_23 , L_23 , V_12 -> V_53 ) ;
F_15 ( V_23 , L_24 , V_12 -> V_20 ) ;
if ( V_12 -> V_20 == 1 )
return 0 ;
if ( V_12 -> V_20 != 2 )
return - V_54 ;
V_50 = F_34 ( sizeof( struct V_49 ) , V_18 ) ;
if ( ! V_50 )
return - V_19 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_2 ) {
F_12 ( V_50 ) ;
return - V_19 ;
}
V_2 -> V_12 [ 0 ] = V_12 -> V_55 -> V_10 [ 0 ] ;
V_2 -> V_12 [ 1 ] = V_12 -> V_55 -> V_10 [ 0 ] ;
V_2 -> V_12 [ 2 ] = V_12 ;
V_2 -> V_50 = V_50 ;
V_50 -> V_56 . V_57 = V_2 ;
V_50 -> V_58 = V_59 ;
F_35 ( & V_12 -> V_60 , V_50 ) ;
F_35 ( & V_2 -> V_12 [ 1 ] -> V_60 , V_50 ) ;
V_2 -> V_60 = & V_2 -> V_12 [ 1 ] -> V_60 ;
V_2 -> V_61 = V_62 ;
F_36 ( & V_2 -> V_4 , false ) ;
F_37 ( & V_2 -> V_24 ) ;
F_37 ( & V_2 -> V_30 ) ;
F_37 ( & V_2 -> V_63 ) ;
F_15 ( V_23 , L_25 ) ;
V_48 = F_38 ( V_2 ) ;
if ( V_48 ) {
F_8 ( L_26 , V_48 ) ;
goto V_64;
}
F_15 ( V_23 , L_27 ) ;
return 0 ;
V_64:
F_35 ( & V_12 -> V_60 , NULL ) ;
F_35 ( & V_2 -> V_12 [ 1 ] -> V_60 , NULL ) ;
F_12 ( V_2 ) ;
F_12 ( V_50 ) ;
return V_48 ;
}
static void F_39 ( struct V_10 * V_12 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 ;
F_15 ( V_23 , L_20 ) ;
F_15 ( V_23 , L_22 , V_12 -> V_52 ) ;
F_15 ( V_23 , L_23 , V_12 -> V_53 ) ;
F_15 ( V_23 , L_28 , V_12 -> V_20 ) ;
if ( V_12 -> V_20 != 1 && V_12 -> V_20 != 2 )
return;
V_50 = F_40 ( & V_12 -> V_60 ) ;
if ( V_50 ) {
V_2 = V_50 -> V_56 . V_57 ;
F_41 ( V_2 ) ;
F_35 ( & V_2 -> V_12 [ 1 ] -> V_60 , NULL ) ;
F_35 ( & V_2 -> V_12 [ 2 ] -> V_60 , NULL ) ;
F_12 ( V_50 ) ;
F_12 ( V_2 ) ;
}
F_15 ( V_23 , L_29 ) ;
}
static int F_42 ( struct V_53 * V_60 )
{
T_6 V_65 ;
struct V_49 * V_50 = F_40 ( V_60 ) ;
struct V_1 * V_2 = V_50 -> V_56 . V_57 ;
int V_32 = 0 ;
F_15 ( V_23 , L_13 ) ;
F_36 ( & V_2 -> V_4 , true ) ;
V_65 = F_43 ( V_2 -> V_12 [ 1 ] ) ;
if ( ! ( V_65 & V_66 ) ) {
F_8 ( L_30 ) ;
return - V_29 ;
}
V_32 = F_44 ( V_2 -> V_12 [ 1 ] , V_66 ) ;
if ( V_32 ) {
F_8 ( L_31 ) ;
return V_32 ;
}
F_45 ( V_2 , false ) ;
return V_32 ;
}
static int F_46 ( struct V_53 * V_60 )
{
struct V_49 * V_50 = F_40 ( V_60 ) ;
struct V_1 * V_2 = V_50 -> V_56 . V_57 ;
F_45 ( V_2 , true ) ;
F_36 ( & V_2 -> V_4 , false ) ;
return 0 ;
}
static int F_47 ( struct V_67 * V_68 )
{
int V_32 ;
F_15 ( V_23 , L_20 ) ;
V_62 = V_68 -> V_60 . V_69 ;
if ( V_62 -> V_70 )
V_62 -> V_70 () ;
V_32 = F_48 ( & V_71 ) ;
if ( V_32 )
F_8 ( L_32 , V_32 ) ;
return V_32 ;
}
static int F_49 ( struct V_67 * V_68 )
{
F_15 ( V_23 , L_20 ) ;
if ( V_62 -> V_72 )
V_62 -> V_72 () ;
F_50 ( & V_71 ) ;
return 0 ;
}
void F_51 ( void )
{
F_15 ( V_23 , L_20 ) ;
if ( V_62 )
F_52 ( & V_73 ) ;
else
F_50 ( & V_71 ) ;
}
void F_53 ( void )
{
int V_32 ;
F_15 ( V_23 , L_20 ) ;
V_32 = F_54 ( & V_73 , F_47 ) ;
if ( V_32 == - V_54 ) {
F_15 ( V_23 , L_33 ) ;
V_32 = F_48 ( & V_71 ) ;
}
if ( V_32 )
F_8 ( L_34 , V_32 ) ;
}
