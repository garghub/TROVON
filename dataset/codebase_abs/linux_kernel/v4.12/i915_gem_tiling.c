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
if ( ! F_11 ( V_5 ) )
return false ;
}
if ( F_12 ( V_2 ) ||
( V_4 == V_18 && F_13 ( V_2 ) ) )
V_14 = 128 ;
else
V_14 = 512 ;
if ( ! V_5 || ! F_5 ( V_5 , V_14 ) )
return false ;
return true ;
}
static bool F_14 ( struct V_19 * V_20 ,
int V_21 , unsigned int V_5 )
{
struct V_1 * V_2 = V_20 -> V_22 -> V_2 ;
T_1 V_3 , V_23 ;
if ( ! F_15 ( V_20 ) )
return true ;
V_3 = F_1 ( V_2 , V_20 -> V_3 , V_21 , V_5 ) ;
if ( V_20 -> V_24 . V_3 < V_3 )
return false ;
V_23 = F_8 ( V_2 , V_20 -> V_3 , V_21 , V_5 ) ;
if ( ! F_5 ( V_20 -> V_24 . V_25 , V_23 ) )
return false ;
return true ;
}
static int
F_16 ( struct V_10 * V_11 ,
int V_21 , unsigned int V_5 )
{
struct V_19 * V_20 ;
int V_26 ;
if ( V_21 == V_7 )
return 0 ;
F_17 (vma, &obj->vma_list, obj_link) {
if ( ! F_18 ( V_20 ) )
break;
if ( F_14 ( V_20 , V_21 , V_5 ) )
continue;
V_26 = F_19 ( V_20 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
int
F_20 ( struct V_10 * V_11 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_1 * V_2 = F_10 ( V_11 -> V_12 . V_13 ) ;
struct V_19 * V_20 ;
int V_27 ;
F_21 ( V_15 & V_28 ) ;
F_2 ( ! F_9 ( V_11 , V_4 , V_5 ) ) ;
F_2 ( ! V_5 ^ ( V_4 == V_7 ) ) ;
F_22 ( & V_2 -> V_29 . V_30 ) ;
if ( ( V_4 | V_5 ) == V_11 -> V_31 )
return 0 ;
if ( F_23 ( V_11 ) )
return - V_32 ;
V_27 = F_16 ( V_11 , V_4 , V_5 ) ;
if ( V_27 )
return V_27 ;
F_24 ( V_11 ) ;
if ( F_23 ( V_11 ) ) {
F_25 ( V_11 ) ;
return - V_32 ;
}
F_26 ( & V_11 -> V_33 . V_34 ) ;
if ( V_11 -> V_33 . V_35 &&
V_11 -> V_33 . V_36 == V_37 &&
V_2 -> V_38 & V_39 ) {
if ( V_4 == V_7 ) {
F_2 ( ! V_11 -> V_33 . V_40 ) ;
F_27 ( V_11 ) ;
V_11 -> V_33 . V_40 = false ;
}
if ( ! F_28 ( V_11 ) ) {
F_2 ( V_11 -> V_33 . V_40 ) ;
F_29 ( V_11 ) ;
V_11 -> V_33 . V_40 = true ;
}
}
F_30 ( & V_11 -> V_33 . V_34 ) ;
F_17 (vma, &obj->vma_list, obj_link) {
if ( ! F_18 ( V_20 ) )
break;
V_20 -> V_41 =
F_1 ( V_2 , V_20 -> V_3 , V_4 , V_5 ) ;
V_20 -> V_42 =
F_8 ( V_2 ,
V_20 -> V_3 , V_4 , V_5 ) ;
if ( V_20 -> V_43 )
V_20 -> V_43 -> V_44 = true ;
}
V_11 -> V_31 = V_4 | V_5 ;
F_25 ( V_11 ) ;
F_31 ( V_11 ) ;
if ( F_32 ( V_11 ) ) {
if ( ! V_11 -> V_45 ) {
V_11 -> V_45 = F_33 ( F_34 ( V_11 -> V_12 . V_3 >> V_46 ) ,
sizeof( long ) , V_47 ) ;
}
} else {
F_35 ( V_11 -> V_45 ) ;
V_11 -> V_45 = NULL ;
}
return 0 ;
}
int
F_36 ( struct V_48 * V_13 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * args = V_49 ;
struct V_10 * V_11 ;
int V_27 ;
V_11 = F_37 ( V_51 , args -> V_53 ) ;
if ( ! V_11 )
return - V_54 ;
if ( ! F_9 ( V_11 , args -> V_21 , args -> V_5 ) ) {
V_27 = - V_55 ;
goto V_27;
}
if ( args -> V_21 == V_7 ) {
args -> V_56 = V_57 ;
args -> V_5 = 0 ;
} else {
if ( args -> V_21 == V_58 )
args -> V_56 = F_10 ( V_13 ) -> V_33 . V_59 ;
else
args -> V_56 = F_10 ( V_13 ) -> V_33 . V_60 ;
if ( args -> V_56 == V_61 )
args -> V_56 = V_62 ;
if ( args -> V_56 == V_63 )
args -> V_56 = V_64 ;
if ( args -> V_56 == V_65 ) {
args -> V_21 = V_7 ;
args -> V_56 = V_57 ;
args -> V_5 = 0 ;
}
}
V_27 = F_38 ( & V_13 -> V_30 ) ;
if ( V_27 )
goto V_27;
V_27 = F_20 ( V_11 , args -> V_21 , args -> V_5 ) ;
F_30 ( & V_13 -> V_30 ) ;
args -> V_5 = F_39 ( V_11 ) ;
args -> V_21 = F_40 ( V_11 ) ;
V_27:
F_41 ( V_11 ) ;
return V_27 ;
}
int
F_42 ( struct V_48 * V_13 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_66 * args = V_49 ;
struct V_1 * V_67 = F_10 ( V_13 ) ;
struct V_10 * V_11 ;
int V_27 = - V_54 ;
F_43 () ;
V_11 = F_44 ( V_51 , args -> V_53 ) ;
if ( V_11 ) {
args -> V_21 =
F_45 ( V_11 -> V_31 ) & V_68 ;
V_27 = 0 ;
}
F_46 () ;
if ( F_47 ( V_27 ) )
return V_27 ;
switch ( args -> V_21 ) {
case V_58 :
args -> V_56 = V_67 -> V_33 . V_59 ;
break;
case V_18 :
args -> V_56 = V_67 -> V_33 . V_60 ;
break;
default:
case V_7 :
args -> V_56 = V_57 ;
break;
}
if ( V_67 -> V_38 & V_39 )
args -> V_69 = V_65 ;
else
args -> V_69 = args -> V_56 ;
if ( args -> V_56 == V_61 )
args -> V_56 = V_62 ;
if ( args -> V_56 == V_63 )
args -> V_56 = V_64 ;
return 0 ;
}
