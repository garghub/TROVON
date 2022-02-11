int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 = NULL , * V_6 = NULL ;
struct V_3 * V_7 = NULL , * V_8 = NULL ;
struct V_3 * V_9 = NULL , * V_10 = NULL , * V_11 = NULL ;
bool V_12 = false ;
T_1 V_13 ;
int V_14 ;
if ( ! V_2 )
return 0 ;
F_2 (entity, mdev) {
switch ( V_4 -> V_15 ) {
case V_16 :
V_5 = V_4 ;
break;
case V_17 :
V_6 = V_4 ;
break;
case V_18 :
V_7 = V_4 ;
break;
case V_19 :
V_8 = V_4 ;
break;
case V_20 :
V_9 = V_4 ;
break;
case V_21 :
V_10 = V_4 ;
break;
case V_22 :
V_11 = V_4 ;
break;
case V_23 :
V_12 = true ;
break;
}
}
if ( ! V_9 && ! V_10 && ! V_11 )
return - V_24 ;
if ( V_12 ) {
if ( ! V_9 )
return - V_24 ;
F_2 (entity, mdev) {
if ( V_4 -> V_15 != V_23 )
continue;
V_14 = F_3 ( V_4 , 0 ,
V_9 , 0 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
}
if ( ! V_8 )
return 0 ;
}
if ( ! V_8 )
return - V_24 ;
if ( V_7 ) {
if ( V_5 ) {
V_14 = F_3 ( V_7 , V_26 ,
V_5 ,
V_27 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_3 ( V_5 , V_28 ,
V_8 , V_29 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
} else {
V_14 = F_3 ( V_7 , V_26 ,
V_8 , V_29 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_6 ) {
V_14 = F_3 ( V_7 , V_30 ,
V_6 ,
V_31 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
} else {
V_6 = V_7 ;
}
}
if ( V_9 ) {
V_14 = F_3 ( V_8 , V_32 ,
V_9 , 0 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_11 ) {
V_14 = F_3 ( V_8 , V_32 ,
V_11 , 0 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_10 ) {
V_14 = F_3 ( V_8 , V_33 ,
V_10 , 0 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
}
V_13 = V_25 ;
F_2 (entity, mdev) {
switch ( V_4 -> V_15 ) {
case V_34 :
if ( ! V_7 )
continue;
V_14 = F_3 ( V_4 , 0 , V_7 ,
V_35 ,
V_13 ) ;
break;
case V_36 :
case V_37 :
V_14 = F_3 ( V_4 , 0 , V_8 ,
V_29 ,
V_13 ) ;
break;
default:
continue;
}
if ( V_14 )
return V_14 ;
V_13 = 0 ;
}
return 0 ;
}
int F_4 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_4 . V_40 . V_2 ;
int V_14 = 0 , V_41 ;
if ( ! V_2 )
return 0 ;
F_5 ( & V_2 -> V_42 ) ;
if ( ! V_2 -> V_43 )
goto V_44;
V_41 = V_2 -> V_43 ( & V_39 -> V_4 , & V_39 -> V_45 ) ;
if ( V_41 )
V_14 = - V_46 ;
V_44:
F_6 ( & V_2 -> V_42 ) ;
return V_14 ;
}
void F_7 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_4 . V_40 . V_2 ;
if ( V_2 ) {
F_5 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_47 )
V_2 -> V_47 ( & V_39 -> V_4 ) ;
F_6 ( & V_2 -> V_42 ) ;
}
}
int F_8 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
if ( V_51 && V_51 -> V_39 )
return F_4 ( V_51 -> V_39 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_53 * V_54 )
{
int V_55 = 0 ;
F_10 ( V_54 , V_4 ) ;
while ( ( V_4 = F_11 ( V_54 ) ) ) {
if ( F_12 ( V_4 ) )
V_55 += V_4 -> V_56 ;
}
return V_55 ;
}
static int F_13 ( struct V_3 * V_4 , int V_57 )
{
struct V_58 * V_59 ;
int V_14 ;
V_59 = F_14 ( V_4 )
? F_15 ( V_4 ) : NULL ;
if ( V_4 -> V_56 == 0 && V_57 > 0 && V_59 != NULL ) {
V_14 = F_16 ( V_59 , V_60 , V_61 , 1 ) ;
if ( V_14 < 0 && V_14 != - V_62 )
return V_14 ;
}
V_4 -> V_56 += V_57 ;
F_17 ( V_4 -> V_56 < 0 ) ;
if ( V_4 -> V_56 == 0 && V_57 < 0 && V_59 != NULL )
F_16 ( V_59 , V_60 , V_61 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 , int V_57 ,
struct V_53 * V_54 )
{
struct V_3 * V_63 = V_4 ;
int V_14 = 0 ;
if ( ! V_57 )
return 0 ;
F_10 ( V_54 , V_4 ) ;
while ( ! V_14 && ( V_4 = F_11 ( V_54 ) ) )
if ( F_14 ( V_4 ) )
V_14 = F_13 ( V_4 , V_57 ) ;
if ( ! V_14 )
return V_14 ;
F_10 ( V_54 , V_63 ) ;
while ( ( V_63 = F_11 ( V_54 ) )
&& V_63 != V_4 )
if ( F_14 ( V_63 ) )
F_13 ( V_63 , - V_57 ) ;
return V_14 ;
}
int F_19 ( struct V_3 * V_4 , int V_55 )
{
struct V_1 * V_2 = V_4 -> V_40 . V_2 ;
int V_57 = V_55 ? 1 : - 1 ;
int V_14 ;
F_5 ( & V_2 -> V_42 ) ;
V_4 -> V_56 += V_57 ;
F_17 ( V_4 -> V_56 < 0 ) ;
V_14 = F_18 ( V_4 , V_57 , & V_2 -> V_64 ) ;
if ( V_14 < 0 )
V_4 -> V_56 -= V_57 ;
F_6 ( & V_2 -> V_42 ) ;
return V_14 ;
}
int F_20 ( struct V_65 * V_66 , T_1 V_13 ,
unsigned int V_67 )
{
struct V_53 * V_54 = & V_66 -> V_40 . V_2 -> V_64 ;
struct V_3 * V_68 = V_66 -> V_68 -> V_4 ;
struct V_3 * V_69 = V_66 -> V_69 -> V_4 ;
int V_70 ;
int V_71 ;
int V_14 = 0 ;
V_70 = F_9 ( V_68 , V_54 ) ;
V_71 = F_9 ( V_69 , V_54 ) ;
if ( V_67 == V_72 &&
! ( V_13 & V_25 ) ) {
F_18 ( V_68 , - V_71 , V_54 ) ;
F_18 ( V_69 , - V_70 , V_54 ) ;
return 0 ;
}
if ( V_67 == V_73 &&
( V_13 & V_25 ) ) {
V_14 = F_18 ( V_68 , V_71 , V_54 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_18 ( V_69 , V_70 , V_54 ) ;
if ( V_14 < 0 )
F_18 ( V_68 , - V_71 , V_54 ) ;
}
return V_14 ;
}
