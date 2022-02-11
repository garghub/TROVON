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
int V_14 ;
if ( ! V_2 || ! V_2 -> V_41 )
return 0 ;
V_14 = V_2 -> V_41 ( & V_39 -> V_4 , & V_39 -> V_42 ) ;
if ( V_14 )
return - V_43 ;
return 0 ;
}
void F_5 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_4 . V_40 . V_2 ;
if ( V_2 && V_2 -> V_44 )
V_2 -> V_44 ( & V_39 -> V_4 ) ;
}
int F_6 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = V_46 -> V_49 ;
if ( V_48 && V_48 -> V_39 )
return F_4 ( V_48 -> V_39 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
int V_52 = 0 ;
F_8 ( V_51 , V_4 ) ;
while ( ( V_4 = F_9 ( V_51 ) ) ) {
if ( F_10 ( V_4 ) )
V_52 += V_4 -> V_53 ;
}
return V_52 ;
}
static int F_11 ( struct V_3 * V_4 , int V_54 )
{
struct V_55 * V_56 ;
int V_14 ;
V_56 = F_12 ( V_4 )
? F_13 ( V_4 ) : NULL ;
if ( V_4 -> V_53 == 0 && V_54 > 0 && V_56 != NULL ) {
V_14 = F_14 ( V_56 , V_57 , V_58 , 1 ) ;
if ( V_14 < 0 && V_14 != - V_59 )
return V_14 ;
}
V_4 -> V_53 += V_54 ;
F_15 ( V_4 -> V_53 < 0 ) ;
if ( V_4 -> V_53 == 0 && V_54 < 0 && V_56 != NULL )
F_14 ( V_56 , V_57 , V_58 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , int V_54 ,
struct V_50 * V_51 )
{
struct V_3 * V_60 = V_4 ;
int V_14 = 0 ;
if ( ! V_54 )
return 0 ;
F_8 ( V_51 , V_4 ) ;
while ( ! V_14 && ( V_4 = F_9 ( V_51 ) ) )
if ( F_12 ( V_4 ) )
V_14 = F_11 ( V_4 , V_54 ) ;
if ( ! V_14 )
return V_14 ;
F_8 ( V_51 , V_60 ) ;
while ( ( V_60 = F_9 ( V_51 ) )
&& V_60 != V_4 )
if ( F_12 ( V_60 ) )
F_11 ( V_60 , - V_54 ) ;
return V_14 ;
}
int F_17 ( struct V_3 * V_4 , int V_52 )
{
struct V_1 * V_2 = V_4 -> V_40 . V_2 ;
int V_54 = V_52 ? 1 : - 1 ;
int V_14 ;
F_18 ( & V_2 -> V_61 ) ;
V_4 -> V_53 += V_54 ;
F_15 ( V_4 -> V_53 < 0 ) ;
V_14 = F_16 ( V_4 , V_54 , & V_2 -> V_62 ) ;
if ( V_14 < 0 )
V_4 -> V_53 -= V_54 ;
F_19 ( & V_2 -> V_61 ) ;
return V_14 ;
}
int F_20 ( struct V_63 * V_64 , T_1 V_13 ,
unsigned int V_65 )
{
struct V_50 * V_51 = & V_64 -> V_40 . V_2 -> V_62 ;
struct V_3 * V_66 = V_64 -> V_66 -> V_4 ;
struct V_3 * V_67 = V_64 -> V_67 -> V_4 ;
int V_68 ;
int V_69 ;
int V_14 = 0 ;
V_68 = F_7 ( V_66 , V_51 ) ;
V_69 = F_7 ( V_67 , V_51 ) ;
if ( V_65 == V_70 &&
! ( V_13 & V_25 ) ) {
F_16 ( V_66 , - V_69 , V_51 ) ;
F_16 ( V_67 , - V_68 , V_51 ) ;
return 0 ;
}
if ( V_65 == V_71 &&
( V_13 & V_25 ) ) {
V_14 = F_16 ( V_66 , V_69 , V_51 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_16 ( V_67 , V_68 , V_51 ) ;
if ( V_14 < 0 )
F_16 ( V_66 , - V_69 , V_51 ) ;
}
return V_14 ;
}
