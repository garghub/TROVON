static int F_1 ( struct V_1 * V_1 , int V_2 )
{
int V_3 ;
if ( V_1 -> V_4 ) {
V_3 = F_2 ( V_1 -> V_4 , V_2 ) ;
if ( V_3 >= 0 )
return V_3 ;
}
return F_2 ( V_1 -> V_5 , V_2 ) ;
}
int F_3 ( struct V_1 * V_1 , int V_2 , char * V_6 ,
T_1 V_7 , void * V_8 )
{
V_2 = F_1 ( V_1 , V_2 ) ;
if ( V_2 < 0 )
return V_2 ;
return F_4 ( V_2 , NULL , V_7 , V_9 ,
V_6 , V_8 ) ;
}
void F_5 ( struct V_1 * V_1 , int V_2 , void * V_8 )
{
V_2 = F_1 ( V_1 , V_2 ) ;
if ( V_2 < 0 )
return;
F_6 ( V_2 , V_8 ) ;
}
int F_7 ( struct V_1 * V_1 , int V_2 , int V_10 )
{
V_2 = F_1 ( V_1 , V_2 ) ;
if ( V_2 < 0 )
return V_2 ;
return F_8 ( V_2 , V_10 ) ;
}
static T_2 F_9 ( int V_2 , void * V_8 )
{
struct V_1 * V_1 = V_8 ;
F_10 ( V_1 -> V_11 , L_1 ) ;
return V_12 ;
}
static T_2 F_11 ( int V_2 , void * V_8 )
{
struct V_1 * V_1 = V_8 ;
F_12 ( V_1 -> V_11 , L_2 ) ;
return V_12 ;
}
static T_2 F_13 ( int V_2 , void * V_8 )
{
struct V_1 * V_1 = V_8 ;
bool V_13 ;
unsigned int V_14 ;
int V_3 ;
V_3 = F_14 ( V_1 -> V_11 ) ;
if ( V_3 < 0 ) {
F_12 ( V_1 -> V_11 , L_3 , V_3 ) ;
return V_15 ;
}
do {
V_13 = false ;
if ( V_1 -> V_4 )
F_15 ( F_16 ( V_1 -> V_16 , 0 ) ) ;
V_3 = F_17 ( V_1 -> V_17 , V_18 ,
& V_14 ) ;
if ( V_3 == 0 && V_14 & V_19 ) {
F_15 ( F_16 ( V_1 -> V_16 , 1 ) ) ;
} else if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 ,
L_4 , V_3 ) ;
}
if ( ! V_1 -> V_20 . V_21 ) {
break;
} else if ( V_1 -> V_20 . V_22 & V_23 &&
F_18 ( V_1 -> V_20 . V_21 ) ) {
V_13 = true ;
} else if ( V_1 -> V_20 . V_22 & V_24 &&
! F_18 ( V_1 -> V_20 . V_21 ) ) {
V_13 = true ;
}
} while ( V_13 );
F_19 ( V_1 -> V_11 ) ;
F_20 ( V_1 -> V_11 ) ;
return V_12 ;
}
static void F_21 ( struct V_25 * V_8 )
{
}
static void F_22 ( struct V_25 * V_8 )
{
}
static int F_23 ( struct V_25 * V_8 , unsigned int V_10 )
{
struct V_1 * V_1 = F_24 ( V_8 ) ;
return F_8 ( V_1 -> V_2 , V_10 ) ;
}
static int F_25 ( struct V_26 * V_27 , unsigned int V_16 ,
T_3 V_28 )
{
struct V_1 * V_8 = V_27 -> V_29 ;
F_26 ( V_16 , V_8 ) ;
F_27 ( V_16 , & V_30 ) ;
F_28 ( V_16 , & V_31 , V_32 ) ;
F_29 ( V_16 , 1 ) ;
F_30 ( V_16 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_1 )
{
int V_33 = V_9 ;
int V_3 , V_34 ;
const struct V_35 * V_36 , * V_2 ;
struct V_25 * V_25 ;
V_1 -> V_37 = true ;
switch ( V_1 -> type ) {
#ifdef F_32
case V_38 :
V_36 = & V_39 ;
V_2 = & V_40 ;
V_1 -> V_37 = false ;
break;
#endif
#ifdef F_33
case V_41 :
case V_42 :
V_36 = & V_43 ;
switch ( V_1 -> V_44 ) {
case 0 ... 2 :
V_2 = & V_45 ;
break;
default:
V_2 = & V_46 ;
break;
}
V_1 -> V_37 = false ;
break;
#endif
#ifdef F_34
case V_47 :
case V_48 :
V_36 = NULL ;
V_2 = & V_49 ;
V_1 -> V_37 = false ;
break;
#endif
#ifdef F_35
case V_50 :
V_36 = & V_51 ;
V_2 = & V_52 ;
V_1 -> V_37 = false ;
break;
#endif
#ifdef F_36
case V_53 :
case V_54 :
V_36 = & V_55 ;
V_2 = & V_56 ;
V_1 -> V_37 = false ;
break;
#endif
default:
F_37 ( L_5 == NULL ) ;
return - V_57 ;
}
F_38 ( V_1 -> V_17 , V_58 , 0 ) ;
if ( ! V_1 -> V_20 . V_22 ) {
V_25 = F_39 ( V_1 -> V_2 ) ;
if ( ! V_25 ) {
F_12 ( V_1 -> V_11 , L_6 ,
V_1 -> V_2 ) ;
return - V_57 ;
}
V_1 -> V_20 . V_22 = F_40 ( V_25 ) ;
switch ( V_1 -> V_20 . V_22 ) {
case V_59 :
case V_60 :
case V_23 :
case V_24 :
break;
case V_61 :
default:
V_1 -> V_20 . V_22 = V_59 ;
break;
}
}
if ( V_1 -> V_20 . V_22 & ( V_60 |
V_23 ) ) {
V_3 = F_41 ( V_1 -> V_17 , V_62 ,
V_63 , 0 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_7 ,
V_3 ) ;
goto V_64;
}
}
V_33 |= V_1 -> V_20 . V_22 ;
V_1 -> V_16 = F_42 ( NULL , 2 , & V_65 ,
V_1 ) ;
if ( ! V_1 -> V_16 ) {
F_12 ( V_1 -> V_11 , L_8 ) ;
V_3 = - V_57 ;
goto V_64;
}
if ( V_36 ) {
V_3 = F_43 ( V_1 -> V_17 ,
F_44 ( V_1 -> V_16 , 0 ) ,
V_9 , 0 , V_36 ,
& V_1 -> V_4 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 ,
L_9 , V_3 ) ;
goto V_64;
}
}
V_3 = F_43 ( V_1 -> V_17 ,
F_44 ( V_1 -> V_16 , 1 ) ,
V_9 , 0 , V_2 ,
& V_1 -> V_5 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_10 , V_3 ) ;
goto V_66;
}
if ( V_1 -> V_20 . V_21 ) {
if ( F_45 ( V_1 -> V_20 . V_21 ) != V_1 -> V_2 ) {
F_46 ( V_1 -> V_11 , L_11 ,
V_1 -> V_2 , V_1 -> V_20 . V_21 ,
F_45 ( V_1 -> V_20 . V_21 ) ) ;
V_1 -> V_2 = F_45 ( V_1 -> V_20 . V_21 ) ;
}
V_3 = F_47 ( V_1 -> V_11 ,
V_1 -> V_20 . V_21 ,
V_67 , L_12 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 ,
L_13 ,
V_1 -> V_20 . V_21 , V_3 ) ;
V_1 -> V_20 . V_21 = 0 ;
}
}
V_3 = F_4 ( V_1 -> V_2 , NULL , F_13 ,
V_33 , L_14 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_15 ,
V_1 -> V_2 , V_3 ) ;
goto V_68;
}
V_34 = F_1 ( V_1 , V_69 ) ;
V_3 = F_4 ( V_34 , NULL , F_9 , V_9 ,
L_16 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_17 ,
V_1 -> V_2 , V_3 ) ;
goto V_70;
}
if ( V_1 -> V_37 ) {
V_34 = F_1 ( V_1 , V_71 ) ;
V_3 = F_4 ( V_34 , NULL , F_11 ,
V_9 ,
L_18 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 ,
L_19 ,
V_1 -> V_2 , V_3 ) ;
goto V_72;
}
}
return 0 ;
V_72:
F_6 ( F_1 ( V_1 , V_69 ) , V_1 ) ;
V_70:
F_6 ( V_1 -> V_2 , V_1 ) ;
V_68:
F_48 ( F_44 ( V_1 -> V_16 , 1 ) ,
V_1 -> V_5 ) ;
V_66:
F_48 ( F_44 ( V_1 -> V_16 , 0 ) ,
V_1 -> V_4 ) ;
V_64:
return V_3 ;
}
int F_49 ( struct V_1 * V_1 )
{
if ( V_1 -> V_37 )
F_6 ( F_1 ( V_1 , V_71 ) ,
V_1 ) ;
F_6 ( F_1 ( V_1 , V_69 ) , V_1 ) ;
F_48 ( F_44 ( V_1 -> V_16 , 1 ) ,
V_1 -> V_5 ) ;
F_48 ( F_44 ( V_1 -> V_16 , 0 ) ,
V_1 -> V_4 ) ;
F_6 ( V_1 -> V_2 , V_1 ) ;
return 0 ;
}
