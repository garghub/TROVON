static int F_1 ( struct V_1 * V_1 , int V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 -> V_4 , V_2 ) ;
if ( V_3 < 0 )
V_3 = F_2 ( V_1 -> V_5 , V_2 ) ;
return V_3 ;
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
static int F_23 ( struct V_26 * V_27 , unsigned int V_16 ,
T_3 V_28 )
{
struct V_29 * V_8 = V_27 -> V_30 ;
F_24 ( V_16 , V_8 ) ;
F_25 ( V_16 , & V_31 , V_32 ) ;
F_26 ( V_16 , 1 ) ;
#ifdef F_27
F_28 ( V_16 , V_33 ) ;
#else
F_29 ( V_16 ) ;
#endif
return 0 ;
}
int F_30 ( struct V_1 * V_1 )
{
int V_34 = V_9 ;
int V_3 , V_35 ;
const struct V_36 * V_37 , * V_2 ;
bool V_38 = true ;
struct V_25 * V_25 ;
switch ( V_1 -> type ) {
#ifdef F_31
case V_39 :
V_37 = & V_40 ;
V_2 = & V_41 ;
V_38 = false ;
break;
#endif
#ifdef F_32
case V_42 :
V_37 = & V_43 ;
V_2 = & V_44 ;
V_38 = false ;
break;
#endif
#ifdef F_33
case V_45 :
V_37 = & V_46 ;
V_2 = & V_47 ;
V_38 = false ;
break;
#endif
default:
F_34 ( L_5 == NULL ) ;
return - V_48 ;
}
F_35 ( V_1 -> V_17 , V_49 , 0 ) ;
if ( ! V_1 -> V_20 . V_22 ) {
V_25 = F_36 ( V_1 -> V_2 ) ;
if ( ! V_25 ) {
F_12 ( V_1 -> V_11 , L_6 ,
V_1 -> V_2 ) ;
return - V_48 ;
}
V_1 -> V_20 . V_22 = F_37 ( V_25 ) ;
switch ( V_1 -> V_20 . V_22 ) {
case V_50 :
case V_51 :
case V_23 :
case V_24 :
break;
case V_52 :
default:
V_1 -> V_20 . V_22 = V_50 ;
break;
}
}
if ( V_1 -> V_20 . V_22 & ( V_51 |
V_23 ) ) {
V_3 = F_38 ( V_1 -> V_17 , V_53 ,
V_54 , 0 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_7 ,
V_3 ) ;
goto V_55;
}
}
V_34 |= V_1 -> V_20 . V_22 ;
V_1 -> V_16 = F_39 ( NULL , 2 , & V_56 ,
V_1 ) ;
if ( ! V_1 -> V_16 ) {
F_12 ( V_1 -> V_11 , L_8 ) ;
V_3 = - V_48 ;
goto V_55;
}
V_3 = F_40 ( V_1 -> V_17 ,
F_41 ( V_1 -> V_16 , 0 ) ,
V_9 , - 1 , V_37 ,
& V_1 -> V_4 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_9 , V_3 ) ;
goto V_57;
}
V_3 = F_40 ( V_1 -> V_17 ,
F_41 ( V_1 -> V_16 , 1 ) ,
V_9 , - 1 , V_2 ,
& V_1 -> V_5 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_9 , V_3 ) ;
goto V_58;
}
V_35 = F_1 ( V_1 , V_59 ) ;
V_3 = F_4 ( V_35 , NULL , F_9 , V_9 ,
L_10 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_11 ,
V_1 -> V_2 , V_3 ) ;
goto V_60;
}
if ( V_38 ) {
V_35 = F_1 ( V_1 , V_61 ) ;
V_3 = F_4 ( V_35 , NULL , F_11 ,
V_9 ,
L_12 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 ,
L_13 ,
V_1 -> V_2 , V_3 ) ;
goto V_62;
}
}
if ( V_1 -> V_20 . V_21 ) {
if ( F_42 ( V_1 -> V_20 . V_21 ) != V_1 -> V_2 ) {
F_43 ( V_1 -> V_11 , L_14 ,
V_1 -> V_2 , V_1 -> V_20 . V_21 ,
F_42 ( V_1 -> V_20 . V_21 ) ) ;
V_1 -> V_2 = F_42 ( V_1 -> V_20 . V_21 ) ;
}
V_3 = F_44 ( V_1 -> V_11 ,
V_1 -> V_20 . V_21 ,
V_63 , L_15 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 ,
L_16 ,
V_1 -> V_20 . V_21 , V_3 ) ;
V_1 -> V_20 . V_21 = 0 ;
}
}
V_3 = F_4 ( V_1 -> V_2 , NULL , F_13 ,
V_34 , L_17 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_18 ,
V_1 -> V_2 , V_3 ) ;
goto V_64;
}
return 0 ;
V_64:
F_6 ( F_1 ( V_1 , V_61 ) , V_1 ) ;
V_62:
F_6 ( F_1 ( V_1 , V_59 ) , V_1 ) ;
V_60:
F_45 ( F_41 ( V_1 -> V_16 , 1 ) ,
V_1 -> V_5 ) ;
V_58:
F_45 ( F_41 ( V_1 -> V_16 , 0 ) ,
V_1 -> V_4 ) ;
V_57:
V_55:
return V_3 ;
}
int F_46 ( struct V_1 * V_1 )
{
F_6 ( F_1 ( V_1 , V_61 ) , V_1 ) ;
F_6 ( F_1 ( V_1 , V_59 ) , V_1 ) ;
F_45 ( F_41 ( V_1 -> V_16 , 1 ) ,
V_1 -> V_5 ) ;
F_45 ( F_41 ( V_1 -> V_16 , 0 ) ,
V_1 -> V_4 ) ;
F_6 ( V_1 -> V_2 , V_1 ) ;
return 0 ;
}
