T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 , unsigned int V_5 )
{
T_1 V_6 ;
F_2 ( ! V_3 ) ;
if ( V_4 == V_7 )
return V_3 ;
F_2 ( ! V_5 ) ;
if ( F_3 ( V_2 ) >= 4 ) {
V_5 *= F_4 ( V_4 ) ;
F_2 ( ! F_5 ( V_5 , V_8 ) ) ;
return F_6 ( V_3 , V_5 ) ;
}
if ( F_7 ( V_2 ) )
V_6 = 1024 * 1024 ;
else
V_6 = 512 * 1024 ;
while ( V_6 < V_3 )
V_6 <<= 1 ;
return V_6 ;
}
T_1 F_8 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
F_2 ( ! V_3 ) ;
if ( V_4 == V_7 )
return V_9 ;
if ( F_3 ( V_2 ) >= 4 )
return V_8 ;
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static bool
F_9 ( struct V_10 * V_11 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_1 * V_2 = F_10 ( V_11 -> V_12 . V_13 ) ;
unsigned int V_14 ;
if ( V_4 == V_7 )
return true ;
if ( V_4 > V_15 )
return false ;
if ( F_3 ( V_2 ) >= 7 ) {
if ( V_5 / 128 > V_16 )
return false ;
} else if ( F_3 ( V_2 ) >= 4 ) {
if ( V_5 / 128 > V_17 )
return false ;
} else {
if ( V_5 > 8192 )
return false ;
if ( F_7 ( V_2 ) ) {
if ( V_11 -> V_12 . V_3 > V_18 << 20 )
return false ;
} else {
if ( V_11 -> V_12 . V_3 > V_18 << 19 )
return false ;
}
}
if ( F_11 ( V_2 ) ||
( V_4 == V_19 && F_12 ( V_2 ) ) )
V_14 = 128 ;
else
V_14 = 512 ;
if ( ! V_5 || ! F_5 ( V_5 , V_14 ) )
return false ;
if ( F_3 ( V_2 ) >= 4 )
return true ;
return F_13 ( V_5 ) ;
}
static bool F_14 ( struct V_20 * V_21 ,
int V_22 , unsigned int V_5 )
{
struct V_1 * V_2 = V_21 -> V_23 -> V_2 ;
T_1 V_3 , V_24 ;
if ( ! F_15 ( V_21 ) )
return true ;
V_3 = F_1 ( V_2 , V_21 -> V_3 , V_22 , V_5 ) ;
if ( V_21 -> V_25 . V_3 < V_3 )
return false ;
V_24 = F_8 ( V_2 , V_21 -> V_3 , V_22 , V_5 ) ;
if ( ! F_5 ( V_21 -> V_25 . V_26 , V_24 ) )
return false ;
return true ;
}
static int
F_16 ( struct V_10 * V_11 ,
int V_22 , unsigned int V_5 )
{
struct V_20 * V_21 ;
int V_27 ;
if ( V_22 == V_7 )
return 0 ;
F_17 (vma, &obj->vma_list, obj_link) {
if ( ! F_18 ( V_21 ) )
break;
if ( F_14 ( V_21 , V_22 , V_5 ) )
continue;
V_27 = F_19 ( V_21 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
int
F_20 ( struct V_10 * V_11 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_1 * V_2 = F_10 ( V_11 -> V_12 . V_13 ) ;
struct V_20 * V_21 ;
int V_28 ;
F_21 ( V_15 & V_29 ) ;
F_2 ( ! F_9 ( V_11 , V_4 , V_5 ) ) ;
F_2 ( ! V_5 ^ ( V_4 == V_7 ) ) ;
F_22 ( & V_2 -> V_30 . V_31 ) ;
if ( ( V_4 | V_5 ) == V_11 -> V_32 )
return 0 ;
if ( V_11 -> V_33 )
return - V_34 ;
V_28 = F_16 ( V_11 , V_4 , V_5 ) ;
if ( V_28 )
return V_28 ;
F_23 ( & V_11 -> V_35 . V_36 ) ;
if ( V_11 -> V_35 . V_37 &&
V_11 -> V_35 . V_38 == V_39 &&
V_2 -> V_40 & V_41 ) {
if ( V_4 == V_7 ) {
F_2 ( ! V_11 -> V_35 . V_42 ) ;
F_24 ( V_11 ) ;
V_11 -> V_35 . V_42 = false ;
}
if ( ! F_25 ( V_11 ) ) {
F_2 ( ! V_11 -> V_35 . V_42 ) ;
F_26 ( V_11 ) ;
V_11 -> V_35 . V_42 = true ;
}
}
F_27 ( & V_11 -> V_35 . V_36 ) ;
F_17 (vma, &obj->vma_list, obj_link) {
if ( ! F_18 ( V_21 ) )
break;
V_21 -> V_43 =
F_1 ( V_2 , V_21 -> V_3 , V_4 , V_5 ) ;
V_21 -> V_44 =
F_8 ( V_2 ,
V_21 -> V_3 , V_4 , V_5 ) ;
if ( V_21 -> V_45 )
V_21 -> V_45 -> V_46 = true ;
}
V_11 -> V_32 = V_4 | V_5 ;
F_28 ( V_11 ) ;
if ( F_29 ( V_11 ) ) {
if ( ! V_11 -> V_47 ) {
V_11 -> V_47 = F_30 ( F_31 ( V_11 -> V_12 . V_3 >> V_48 ) ,
sizeof( long ) , V_49 ) ;
}
} else {
F_32 ( V_11 -> V_47 ) ;
V_11 -> V_47 = NULL ;
}
return 0 ;
}
int
F_33 ( struct V_50 * V_13 , void * V_51 ,
struct V_52 * V_53 )
{
struct V_54 * args = V_51 ;
struct V_10 * V_11 ;
int V_28 ;
V_11 = F_34 ( V_53 , args -> V_55 ) ;
if ( ! V_11 )
return - V_56 ;
if ( ! F_9 ( V_11 , args -> V_22 , args -> V_5 ) ) {
V_28 = - V_57 ;
goto V_28;
}
if ( args -> V_22 == V_7 ) {
args -> V_58 = V_59 ;
args -> V_5 = 0 ;
} else {
if ( args -> V_22 == V_60 )
args -> V_58 = F_10 ( V_13 ) -> V_35 . V_61 ;
else
args -> V_58 = F_10 ( V_13 ) -> V_35 . V_62 ;
if ( args -> V_58 == V_63 )
args -> V_58 = V_64 ;
if ( args -> V_58 == V_65 )
args -> V_58 = V_66 ;
if ( args -> V_58 == V_67 ) {
args -> V_22 = V_7 ;
args -> V_58 = V_59 ;
args -> V_5 = 0 ;
}
}
V_28 = F_35 ( & V_13 -> V_31 ) ;
if ( V_28 )
goto V_28;
V_28 = F_20 ( V_11 , args -> V_22 , args -> V_5 ) ;
F_27 ( & V_13 -> V_31 ) ;
args -> V_5 = F_36 ( V_11 ) ;
args -> V_22 = F_37 ( V_11 ) ;
V_28:
F_38 ( V_11 ) ;
return V_28 ;
}
int
F_39 ( struct V_50 * V_13 , void * V_51 ,
struct V_52 * V_53 )
{
struct V_68 * args = V_51 ;
struct V_1 * V_69 = F_10 ( V_13 ) ;
struct V_10 * V_11 ;
int V_28 = - V_56 ;
F_40 () ;
V_11 = F_41 ( V_53 , args -> V_55 ) ;
if ( V_11 ) {
args -> V_22 =
F_42 ( V_11 -> V_32 ) & V_70 ;
V_28 = 0 ;
}
F_43 () ;
if ( F_44 ( V_28 ) )
return V_28 ;
switch ( args -> V_22 ) {
case V_60 :
args -> V_58 = V_69 -> V_35 . V_61 ;
break;
case V_19 :
args -> V_58 = V_69 -> V_35 . V_62 ;
break;
default:
case V_7 :
args -> V_58 = V_59 ;
break;
}
if ( V_69 -> V_40 & V_41 )
args -> V_71 = V_67 ;
else
args -> V_71 = args -> V_58 ;
if ( args -> V_58 == V_63 )
args -> V_58 = V_64 ;
if ( args -> V_58 == V_65 )
args -> V_58 = V_66 ;
return 0 ;
}
