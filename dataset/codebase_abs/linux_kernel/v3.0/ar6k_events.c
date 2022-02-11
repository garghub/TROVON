int F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
F_2 ( V_5 ,
( L_1 ,
( unsigned long ) V_4 ,
V_2 ) ) ;
F_3 ( V_4 , V_2 ) ;
F_2 ( V_5 ,
( L_2 ) ) ;
return 0 ;
}
int F_4 ( struct V_6 * V_7 ,
T_1 * V_8 ,
int V_9 )
{
int V_2 = 0 ;
int V_10 = V_9 / V_11 ;
F_5 ( V_10 > 0 ) ;
F_2 ( V_5 , ( L_3 ) ) ;
while ( true ) {
if ( V_7 -> V_12 != NULL ) {
struct V_13 V_14 ;
#ifdef F_6
V_14 . V_15 = 1 ;
#endif
V_2 = V_7 -> V_12 ( V_7 -> V_16 ,
& V_14 ,
NULL ) ;
if ( V_2 )
{
F_2 ( V_17 , ( L_4 ) ) ;
break;
}
if ( V_14 . V_18 & V_19 )
{
* V_8 = V_14 . V_20 ;
break;
}
} else {
V_2 = F_7 ( V_7 -> V_16 ,
V_21 ,
( V_22 * ) & V_7 -> V_23 ,
V_24 ,
V_25 ,
NULL ) ;
if ( V_2 ) {
F_2 ( V_17 , ( L_5 ) ) ;
break;
}
if ( V_7 -> V_23 . V_26 & ( 1 << V_27 ) ) {
if ( V_7 -> V_23 . V_28 & ( 1 << V_27 ) )
{
* V_8 = V_7 -> V_23 . V_29 [ V_27 ] ;
break;
}
}
}
V_10 -- ;
if ( V_10 <= 0 ) {
F_2 ( V_17 , ( L_6 ) ) ;
V_2 = V_30 ;
if ( V_7 -> V_23 . V_31 & V_32 ) {
F_8 ( V_7 ) ;
}
break;
}
F_9 ( V_11 ) ;
F_2 ( V_5 , ( L_7 , V_10 ) ) ;
}
F_2 ( V_5 , ( L_8 ) ) ;
return V_2 ;
}
static int F_10 ( struct V_6 * V_7 )
{
int V_2 ;
V_22 V_33 ;
V_22 V_34 [ 4 ] ;
F_2 ( V_35 , ( L_9 ) ) ;
V_33 = V_7 -> V_23 . V_33 &
V_7 -> V_36 . V_37 ;
F_5 ( V_33 ) ;
F_2 ( V_35 ,
( L_10 ,
V_33 ) ) ;
V_7 -> V_23 . V_33 &= ~ V_33 ;
V_34 [ 0 ] = V_33 ;
V_34 [ 1 ] = 0 ;
V_34 [ 2 ] = 0 ;
V_34 [ 3 ] = 0 ;
V_2 = F_7 ( V_7 -> V_16 ,
V_38 ,
V_34 ,
4 ,
V_39 ,
NULL ) ;
F_5 ( V_2 == 0 ) ;
return V_2 ;
}
static int F_11 ( struct V_6 * V_7 )
{
int V_2 ;
V_22 V_40 ;
V_22 V_34 [ 4 ] ;
F_2 ( V_35 , ( L_11 ) ) ;
V_40 = V_7 -> V_23 . V_40 & 0x0F ;
F_5 ( V_40 ) ;
F_2 ( V_35 ,
( L_12 ,
V_40 ) ) ;
if ( F_12 ( V_40 ) ) {
F_2 ( V_35 , ( L_13 ) ) ;
}
if ( F_13 ( V_40 ) ) {
F_2 ( V_17 , ( L_14 ) ) ;
}
if ( F_14 ( V_40 ) ) {
F_2 ( V_17 , ( L_15 ) ) ;
}
V_7 -> V_23 . V_40 &= ~ V_40 ;
V_34 [ 0 ] = V_40 ;
V_34 [ 1 ] = 0 ;
V_34 [ 2 ] = 0 ;
V_34 [ 3 ] = 0 ;
V_2 = F_7 ( V_7 -> V_16 ,
V_41 ,
V_34 ,
4 ,
V_39 ,
NULL ) ;
F_5 ( V_2 == 0 ) ;
return V_2 ;
}
static int F_8 ( struct V_6 * V_7 )
{
T_1 V_42 ;
int V_2 ;
F_2 ( V_17 , ( L_16 ) ) ;
if ( V_7 -> V_43 != NULL ) {
V_7 -> V_43 ( V_7 -> V_44 ) ;
}
if ( V_7 -> V_45 ) {
F_15 ( V_7 ) ;
}
V_2 = F_7 ( V_7 -> V_16 ,
V_46 ,
( V_22 * ) & V_42 ,
4 ,
V_25 ,
NULL ) ;
F_5 ( V_2 == 0 ) ;
return V_2 ;
}
static int F_16 ( struct V_6 * V_7 )
{
V_22 V_31 ;
F_2 ( V_35 , ( L_17 ) ) ;
V_31 = V_7 -> V_23 . V_31 &
V_7 -> V_36 . V_47 ;
F_2 ( V_35 ,
( L_18 ,
V_31 ) ) ;
if ( V_31 & V_32 ) {
return F_8 ( V_7 ) ;
}
return 0 ;
}
static void F_17 ( void * V_48 , struct V_3 * V_4 )
{
struct V_6 * V_7 = (struct V_6 * ) V_48 ;
T_1 V_49 = 0 ;
bool V_50 = false ;
F_2 ( V_35 , ( L_19 , ( unsigned long ) V_7 ) ) ;
do {
if ( V_4 -> V_51 ) {
F_2 ( V_17 ,
( L_20 , V_4 -> V_51 ) ) ;
break;
}
if ( V_7 -> V_12 != NULL ) {
struct V_13 * V_52 = (struct V_13 * ) V_4 -> V_53 ;
if ( V_52 -> V_18 & V_19 ) {
V_49 = V_52 -> V_20 ;
if ( 0 == V_49 ) {
F_2 ( V_17 , ( L_21 ) ) ;
}
}
if ( V_52 -> V_18 & V_54 ) {
V_50 = true ;
}
} else {
struct V_55 * V_56 = (struct V_55 * ) V_4 -> V_53 ;
V_22 V_26 ;
V_26 = V_56 -> V_26 & V_7 -> V_36 . V_57 ;
if ( V_26 & ( 1 << V_27 ) ) {
V_26 &= ~ ( 1 << V_27 ) ;
if ( V_56 -> V_28 & ( 1 << V_27 ) ) {
V_49 = V_56 -> V_29 [ V_27 ] ;
if ( 0 == V_49 ) {
F_2 ( V_17 , ( L_22 ) ) ;
}
}
}
if ( V_26 ) {
V_50 = true ;
}
}
if ( V_50 || ( V_49 == 0 ) ) {
F_2 ( V_35 ,
( L_23 ,
V_50 , V_49 ) ) ;
F_18 ( V_7 -> V_16 ) ;
} else {
int V_58 = 0 ;
int V_2 ;
F_2 ( V_35 ,
( L_24 ,
V_49 ) ) ;
V_2 = V_7 -> V_59 ( V_7 -> V_44 , & V_49 , 1 , NULL , & V_58 ) ;
if ( ! V_2 && ! V_58 ) {
F_2 ( V_35 , ( L_25 ) ) ;
F_19 ( V_7 ) ;
}
}
} while ( false );
F_20 ( V_7 , V_4 ) ;
F_2 ( V_35 , ( L_26 ) ) ;
}
int F_21 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
int V_2 = 0 ;
struct V_3 * V_60 ;
F_2 ( V_35 , ( L_27 , ( unsigned long ) V_7 ) ) ;
do {
if ( V_61 == V_7 -> V_62 ) {
break;
}
if ( V_7 -> V_63 == 0 ) {
F_2 ( V_35 , ( L_28 ) ) ;
F_18 ( V_7 -> V_16 ) ;
break;
}
V_60 = F_22 ( V_7 ) ;
if ( NULL == V_60 ) {
V_2 = V_64 ;
F_5 ( false ) ;
break;
}
V_60 -> V_65 = F_17 ;
V_60 -> V_66 = V_7 ;
if ( V_7 -> V_12 ) {
V_2 = V_7 -> V_12 ( V_7 -> V_16 ,
(struct V_13 * ) V_60 -> V_53 ,
V_60 ) ;
} else {
V_2 = F_7 ( V_7 -> V_16 ,
V_21 ,
V_60 -> V_53 ,
V_24 ,
V_67 ,
V_60 ) ;
}
F_2 ( V_35 , ( L_29 ) ) ;
} while ( false );
F_2 ( V_35 , ( L_30 ) ) ;
return V_2 ;
}
void F_19 ( struct V_6 * V_7 )
{
F_2 ( V_35 , ( L_31 ) ) ;
F_18 ( V_7 -> V_16 ) ;
}
static int F_23 ( struct V_6 * V_7 , bool * V_68 , bool * V_69 )
{
int V_2 = 0 ;
V_22 V_26 = 0 ;
T_1 V_49 = 0 ;
F_2 ( V_35 , ( L_32 , ( unsigned long ) V_7 ) ) ;
do {
if ( V_7 -> V_36 . V_57 == 0 ) {
break;
}
if ( V_7 -> V_12 != NULL ) {
struct V_13 V_14 ;
#ifdef F_6
V_14 . V_15 = 0 ;
#endif
V_2 = V_7 -> V_12 ( V_7 -> V_16 ,
& V_14 ,
NULL ) ;
if ( V_2 ) {
break;
}
if ( V_14 . V_18 & V_19 ) {
V_49 = V_14 . V_20 ;
if ( 0 == V_49 ) {
F_2 ( V_17 , ( L_33 ) ) ;
}
}
if ( ! ( V_14 . V_18 & V_54 ) ||
! ( V_7 -> V_36 . V_57 & V_70 ) ) {
break;
}
}
#ifdef F_24
V_7 -> V_23 . V_26 = 0 ;
V_7 -> V_23 . V_28 = 0 ;
V_7 -> V_23 . V_71 = 0 ;
V_7 -> V_23 . V_29 [ 0 ] = 0 ;
V_7 -> V_23 . V_29 [ 1 ] = 0xaaa5555 ;
#endif
V_2 = F_7 ( V_7 -> V_16 ,
V_21 ,
( V_22 * ) & V_7 -> V_23 ,
V_24 ,
V_25 ,
NULL ) ;
if ( V_2 ) {
break;
}
#ifdef F_25
if ( F_26 ( V_35 ) ) {
F_27 ( V_7 ,
& V_7 -> V_23 ,
& V_7 -> V_36 ) ;
}
#endif
V_26 = V_7 -> V_23 . V_26 &
V_7 -> V_36 . V_57 ;
if ( NULL == V_7 -> V_12 ) {
if ( V_26 & ( 1 << V_27 ) ) {
V_26 &= ~ ( 1 << V_27 ) ;
if ( V_7 -> V_23 . V_28 & ( 1 << V_27 ) ) {
V_49 = V_7 -> V_23 . V_29 [ V_27 ] ;
if ( 0 == V_49 ) {
F_2 ( V_17 , ( L_34 ) ) ;
}
}
}
} else {
V_26 &= ~ ( 1 << V_27 ) ;
}
if ( V_7 -> V_45 ) {
V_2 = F_28 ( V_7 ) ;
}
} while ( false );
do {
if ( V_2 ) {
break;
}
if ( ( 0 == V_26 ) && ( 0 == V_49 ) ) {
* V_68 = true ;
break;
}
if ( V_49 != 0 ) {
int V_58 = 0 ;
F_2 ( V_35 , ( L_35 , V_49 ) ) ;
V_2 = V_7 -> V_59 ( V_7 -> V_44 , & V_49 , 1 , V_69 , & V_58 ) ;
if ( V_2 ) {
break;
}
if ( ! V_58 ) {
* V_69 = false ;
V_7 -> V_63 = 0 ;
}
}
F_2 ( V_35 ,
( L_36 ,
V_26 ) ) ;
if ( F_29 ( V_26 ) ) {
V_2 = F_10 ( V_7 ) ;
if ( V_2 ) {
break;
}
}
if ( F_30 ( V_26 ) ) {
V_2 = F_11 ( V_7 ) ;
if ( V_2 ) {
break;
}
}
if ( F_31 ( V_26 ) ) {
V_2 = F_16 ( V_7 ) ;
if ( V_2 ) {
break;
}
}
} while ( false );
if ( ! ( * V_69 ) && ( V_7 -> V_63 == 0 ) && ( V_7 -> V_12 == NULL ) ) {
F_2 ( V_35 , ( L_37 ) ) ;
* V_68 = true ;
}
F_2 ( V_35 , ( L_38 ,
* V_68 , * V_69 , V_2 ) ) ;
return V_2 ;
}
int F_32 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
int V_2 = 0 ;
bool V_72 = false ;
bool V_73 = false ;
F_2 ( V_35 , ( L_39 , ( unsigned long ) V_7 ) ) ;
V_7 -> V_74 = 0 ;
V_7 -> V_63 = 0 ;
while ( ! V_72 ) {
V_2 = F_23 ( V_7 , & V_72 , & V_73 ) ;
if ( V_2 ) {
break;
}
if ( V_61 == V_7 -> V_62 ) {
V_73 = false ;
if ( V_7 -> V_75 && F_33 ( V_7 ) ) {
break;
}
}
if ( V_73 ) {
break;
}
}
if ( ! V_2 && ! V_73 ) {
if ( V_7 -> V_75 ) {
F_2 ( V_35 , ( L_40 , V_7 -> V_74 ) ) ;
} else {
F_2 ( V_35 , ( L_41 ) ) ;
F_18 ( V_7 -> V_16 ) ;
}
}
F_2 ( V_35 , ( L_42 ) ) ;
return V_2 ;
}
void F_34 ( struct V_6 * V_7 )
{
int V_2 ;
struct V_76 V_77 ;
struct V_55 V_78 ;
F_35 ( V_7 ) ;
memcpy ( & V_77 , & V_7 -> V_36 , V_79 ) ;
F_36 ( V_7 ) ;
V_2 = F_7 ( V_7 -> V_16 ,
V_21 ,
( V_22 * ) & V_78 ,
V_24 ,
V_25 ,
NULL ) ;
if ( V_2 ) {
F_2 ( V_17 ,
( L_43 , V_2 ) ) ;
return;
}
F_27 ( V_7 , & V_78 , & V_77 ) ;
if ( V_7 -> V_80 . V_81 != NULL ) {
V_7 -> V_80 . V_81 ( V_7 -> V_80 . V_82 ) ;
}
F_37 ( V_7 -> V_16 , V_83 , NULL , 0 ) ;
}
