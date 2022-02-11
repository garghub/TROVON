void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_5 * V_6 ;
unsigned int V_7 ;
int V_8 ;
int V_9 ;
static T_1 V_10 = FALSE ;
memset ( ( char * ) V_2 -> V_11 , 0 , sizeof( V_2 -> V_11 ) ) ;
V_4 = V_2 -> V_11 ;
V_6 = V_12 ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ ) {
for ( V_8 = 0 ; V_8 < V_6 -> V_14 ; V_8 ++ ) {
V_4 -> V_15 = V_6 -> V_16 ;
V_4 -> V_17 = V_6 -> V_18 ;
V_4 -> V_19 = V_6 -> V_8 + V_8 ;
#ifndef F_2
V_4 -> V_20 = & V_10 ;
V_4 -> V_21 = & V_10 ;
#endif
V_4 ++ ;
}
V_6 ++ ;
}
if ( ( unsigned int ) ( V_4 - V_2 -> V_11 ) > V_22 ) {
F_3 ( V_2 , V_23 , V_24 ) ;
}
V_2 -> V_11 [ 0 ] . V_21 = & V_2 -> V_25 . V_26 ;
V_2 -> V_11 [ 1 ] . V_21 =
& V_2 -> V_25 . V_27 [ V_28 ] . V_29 ;
V_2 -> V_11 [ 2 ] . V_21 =
& V_2 -> V_25 . V_27 [ V_28 ] . V_30 ;
V_2 -> V_11 [ 3 ] . V_21 =
& V_2 -> V_25 . V_27 [ V_28 ] . V_31 ;
V_2 -> V_11 [ 4 ] . V_20 = & V_2 -> V_25 . V_27 [ V_28 ] . V_32 ;
V_2 -> V_11 [ 5 ] . V_20 = & V_2 -> V_25 . V_27 [ V_28 ] . V_33 ;
V_9 = 6 ;
for ( V_7 = 0 ; V_7 < V_34 ; V_7 ++ ) {
V_2 -> V_11 [ V_9 + 0 * V_34 ] . V_21 =
& V_2 -> V_25 . V_35 [ V_7 ] . V_36 ;
V_2 -> V_11 [ V_9 + 1 * V_34 ] . V_21 =
& V_2 -> V_25 . V_35 [ V_7 ] . V_37 ;
V_2 -> V_11 [ V_9 + 2 * V_34 ] . V_20 =
& V_2 -> V_25 . V_35 [ V_7 ] . V_38 ;
V_2 -> V_11 [ V_9 + 3 * V_34 ] . V_20 =
& V_2 -> V_25 . V_35 [ V_7 ] . V_39 ;
V_9 ++ ;
}
#ifdef F_2
for ( V_7 = 0 , V_4 = V_2 -> V_11 ; V_7 < V_22 ; V_7 ++ , V_4 ++ ) {
if ( F_4 ( V_4 -> V_15 ) ) {
if ( ! V_4 -> V_21 ) {
F_3 ( V_2 , V_40 , V_41 ) ;
}
V_4 -> V_20 = & V_10 ;
}
else {
if ( ! V_4 -> V_20 ) {
F_3 ( V_2 , V_42 , V_43 ) ;
}
V_4 -> V_21 = & V_10 ;
}
}
#endif
V_2 -> V_44 . V_45 = F_5 () ;
V_2 -> V_44 . V_46 = V_47 ;
}
static struct V_3 * F_6 ( struct V_1 * V_2 , int V_16 , int V_8 )
{
unsigned int V_7 ;
struct V_3 * V_4 ;
for ( V_7 = 0 , V_4 = V_2 -> V_11 ; V_7 < V_22 ; V_7 ++ , V_4 ++ ) {
if ( V_4 -> V_15 == V_16 && V_4 -> V_19 == V_8 )
return V_4 ;
}
return NULL ;
}
void F_7 ( struct V_1 * V_2 , int V_16 , int V_8 , int V_48 )
{
struct V_3 * V_4 ;
int V_49 = 0 ;
int V_50 = 0 ;
int V_51 = 0 ;
int V_52 ;
int V_53 = 2 * V_54 ;
if ( V_16 == V_55 && V_48 ) {
F_8 ( V_2 , V_56 ) ;
}
if ( V_16 ) {
F_9 ( L_1 , V_57 [ V_16 ] , V_8 ) ;
if ( ! ( V_4 = F_6 ( V_2 , V_16 , V_8 ) ) ) {
F_9 ( L_2 ) ;
return ;
}
if ( F_4 ( V_16 ) ) {
if ( * V_4 -> V_21 == V_48 )
return ;
}
F_10 ( V_2 , V_2 -> V_25 . V_58 ) ;
if ( F_4 ( V_16 ) ) {
F_9 ( L_3 , V_48 ? L_4 : L_5 ) ;
if ( V_48 ) {
* V_4 -> V_21 = TRUE ;
V_4 -> V_59 = TRUE ;
V_2 -> V_44 . V_60 = TRUE ;
V_49 = TRUE ;
}
else {
* V_4 -> V_21 = FALSE ;
V_50 = TRUE ;
}
}
else {
if ( V_4 -> V_59 ) {
* V_4 -> V_20 = TRUE ;
}
else {
V_4 -> V_59 = TRUE ;
* V_4 -> V_20 = FALSE ;
}
V_2 -> V_44 . V_60 = TRUE ;
V_51 = TRUE ;
}
#ifdef F_11
F_12 ( V_2 , V_4 ) ;
#endif
}
V_52 = F_5 () - V_2 -> V_44 . V_45 ;
switch ( V_2 -> V_44 . V_46 ) {
case V_47 :
if ( V_49 && V_52 < V_53 ) {
V_2 -> V_44 . V_61 = V_62 ;
V_2 -> V_44 . V_46 = V_63 ;
break ;
}
if ( V_50 && V_52 < V_53 ) {
V_2 -> V_44 . V_46 = V_63 ;
break ;
}
if ( V_51 && V_52 < V_53 ) {
V_2 -> V_44 . V_46 = V_63 ;
break ;
}
if ( V_49 && V_52 >= V_53 ) {
V_2 -> V_44 . V_61 = V_62 ;
V_2 -> V_44 . V_45 = F_5 () ;
F_13 ( V_2 ) ;
break ;
}
if ( V_50 && V_52 >= V_53 ) {
V_2 -> V_44 . V_45 = F_5 () ;
F_13 ( V_2 ) ;
break ;
}
if ( V_51 && V_52 >= V_53 ) {
V_2 -> V_44 . V_45 = F_5 () ;
F_13 ( V_2 ) ;
break ;
}
if ( V_2 -> V_44 . V_60 && ( V_64 ) V_52 >=
V_2 -> V_44 . V_61 ) {
V_2 -> V_44 . V_61 *= 2 ;
if ( V_2 -> V_44 . V_61 > V_65 )
V_2 -> V_44 . V_61 = V_65 ;
V_2 -> V_44 . V_45 = F_5 () ;
F_13 ( V_2 ) ;
break ;
}
if ( ! V_2 -> V_25 . V_66 ) {
V_2 -> V_44 . V_46 = V_67 ;
break ;
}
break ;
case V_63 :
if ( V_52 >= V_53 ) {
V_2 -> V_44 . V_46 = V_47 ;
V_2 -> V_44 . V_45 = F_5 () ;
F_13 ( V_2 ) ;
break ;
}
if ( V_49 ) {
V_2 -> V_44 . V_61 = V_62 ;
}
if ( ! V_2 -> V_25 . V_66 ) {
V_2 -> V_44 . V_46 = V_67 ;
break ;
}
break ;
case V_67 :
if ( V_2 -> V_25 . V_66 ) {
V_2 -> V_44 . V_46 = V_47 ;
V_2 -> V_44 . V_45 = F_5 () ;
V_2 -> V_44 . V_61 = V_62 ;
F_14 ( V_2 ) ;
break ;
}
break ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_7 ;
for ( V_7 = 0 , V_4 = V_2 -> V_11 ; V_7 < V_22 ; V_7 ++ , V_4 ++ ) {
V_4 -> V_59 = FALSE ;
if ( F_4 ( V_4 -> V_15 ) )
* V_4 -> V_21 = FALSE ;
}
V_2 -> V_44 . V_60 = FALSE ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_7 ;
V_2 -> V_44 . V_60 = FALSE ;
for ( V_7 = 0 , V_4 = V_2 -> V_11 ; V_7 < V_22 ; V_7 ++ , V_4 ++ ) {
if ( F_4 ( V_4 -> V_15 ) ) {
if ( * V_4 -> V_21 == FALSE )
V_4 -> V_59 = FALSE ;
else
V_2 -> V_44 . V_60 = TRUE ;
}
else {
V_4 -> V_59 = FALSE ;
* V_4 -> V_20 = FALSE ;
}
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_68 * V_69 ;
struct V_3 * V_4 ;
F_16 ( struct V_70 , V_71 ) ;
T_2 * V_72 ;
unsigned int V_7 ;
static const struct V_73 V_74 = {
{ 0x80 , 0x01 , 0x43 , 0x00 , 0x80 , 0x08 }
} ;
if ( ! V_2 -> V_75 . V_76 )
return ;
if ( ! ( V_72 = F_17 ( V_2 , V_77 , V_78 , 0 ) ) )
return ;
F_8 ( V_2 , V_79 ) ;
V_69 = F_18 ( V_72 , struct V_68 * ) ;
V_69 -> V_80 = V_74 ;
V_71 . V_81 = V_82 ;
V_71 . V_83 = 0 ;
V_71 . V_84 = 0 ;
V_71 . V_85 = ( void * ) ( V_69 + 1 ) ;
F_19 ( V_2 , & V_71 , ( V_86 ) V_87 , 0 , 0 ) ;
F_19 ( V_2 , & V_71 , ( V_86 ) V_88 , 0 , 0 ) ;
for ( V_7 = 0 , V_4 = V_2 -> V_11 ; V_7 < V_22 ; V_7 ++ , V_4 ++ ) {
if ( V_4 -> V_59 ) {
F_19 ( V_2 , & V_71 , V_4 -> V_17 ,
( int ) V_4 -> V_19 , 0 ) ;
}
}
V_69 -> V_89 = V_82 - V_71 . V_81 ;
V_72 -> V_90 = V_69 -> V_89 + sizeof( struct V_68 ) ;
F_9 ( L_6 , V_69 , V_72 -> V_90 ) ;
F_9 ( L_7 ,
V_2 -> V_44 . V_46 , V_2 -> V_44 . V_61 / V_54 ) ;
#ifdef F_2
F_20 ( V_2 , V_69 , L_8 ) ;
#endif
F_21 ( V_2 , V_72 , V_91 , 0 ) ;
F_15 ( V_2 ) ;
}
