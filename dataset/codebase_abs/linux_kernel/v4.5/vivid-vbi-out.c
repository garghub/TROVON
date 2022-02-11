static int F_1 ( struct V_1 * V_2 ,
unsigned * V_3 , unsigned * V_4 ,
unsigned V_5 [] , void * V_6 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
bool V_9 = V_8 -> V_10 & V_11 ;
unsigned V_12 = V_2 -> type == V_13 ?
36 * sizeof( struct V_14 ) :
1440 * 2 * ( V_9 ? 12 : 18 ) ;
if ( ! F_3 ( V_8 ) )
return - V_15 ;
V_5 [ 0 ] = V_12 ;
if ( V_2 -> V_16 + * V_3 < 2 )
* V_3 = 2 - V_2 -> V_16 ;
* V_4 = 1 ;
return 0 ;
}
static int F_4 ( struct V_17 * V_18 )
{
struct V_7 * V_8 = F_2 ( V_18 -> V_1 ) ;
bool V_9 = V_8 -> V_10 & V_11 ;
unsigned V_12 = V_18 -> V_1 -> type == V_13 ?
36 * sizeof( struct V_14 ) :
1440 * 2 * ( V_9 ? 12 : 18 ) ;
F_5 ( V_8 , 1 , L_1 , V_19 ) ;
if ( V_8 -> V_20 ) {
V_8 -> V_20 = false ;
return - V_15 ;
}
if ( F_6 ( V_18 , 0 ) < V_12 ) {
F_5 ( V_8 , 1 , L_2 ,
V_19 , F_6 ( V_18 , 0 ) , V_12 ) ;
return - V_15 ;
}
F_7 ( V_18 , 0 , V_12 ) ;
return 0 ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_21 * V_22 = F_9 ( V_18 ) ;
struct V_7 * V_8 = F_2 ( V_18 -> V_1 ) ;
struct V_23 * V_24 = F_10 ( V_22 , struct V_23 , V_18 ) ;
F_5 ( V_8 , 1 , L_1 , V_19 ) ;
F_11 ( & V_8 -> V_25 ) ;
F_12 ( & V_24 -> V_26 , & V_8 -> V_27 ) ;
F_13 ( & V_8 -> V_25 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_28 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_29 ;
F_5 ( V_8 , 1 , L_1 , V_19 ) ;
V_8 -> V_30 = 0 ;
if ( V_8 -> V_31 ) {
V_8 -> V_31 = false ;
V_29 = - V_15 ;
} else {
V_29 = F_15 ( V_8 , & V_8 -> V_32 ) ;
}
if ( V_29 ) {
struct V_23 * V_24 , * V_33 ;
F_16 (buf, tmp, &dev->vbi_out_active, list) {
F_17 ( & V_24 -> V_26 ) ;
F_18 ( & V_24 -> V_18 . V_34 ,
V_35 ) ;
}
}
return V_29 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_5 ( V_8 , 1 , L_1 , V_19 ) ;
F_20 ( V_8 , & V_8 -> V_32 ) ;
V_8 -> V_36 = false ;
V_8 -> V_37 [ 0 ] = false ;
V_8 -> V_37 [ 1 ] = false ;
}
int F_21 ( struct V_38 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_7 * V_8 = F_22 ( V_38 ) ;
struct V_42 * V_43 = & V_41 -> V_44 . V_43 ;
bool V_9 = V_8 -> V_10 & V_11 ;
if ( ! F_3 ( V_8 ) || ! V_8 -> V_45 )
return - V_15 ;
V_43 -> V_46 = 25000000 ;
V_43 -> V_47 = 24 ;
V_43 -> V_48 = 1440 ;
V_43 -> V_49 = V_50 ;
V_43 -> V_51 [ 0 ] = V_9 ? V_52 + 9 : V_53 + 5 ;
V_43 -> V_51 [ 1 ] = V_9 ? V_54 + 9 : V_55 + 5 ;
V_43 -> V_28 [ 0 ] = V_43 -> V_28 [ 1 ] = V_9 ? 12 : 18 ;
V_43 -> V_56 = V_8 -> V_57 ? V_58 : 0 ;
V_43 -> V_59 [ 0 ] = 0 ;
V_43 -> V_59 [ 1 ] = 0 ;
return 0 ;
}
int F_23 ( struct V_38 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_7 * V_8 = F_22 ( V_38 ) ;
int V_60 = F_21 ( V_38 , V_39 , V_41 ) ;
if ( V_60 )
return V_60 ;
if ( F_24 ( & V_8 -> V_61 ) )
return - V_62 ;
V_8 -> V_63 = false ;
V_8 -> V_64 . V_65 -> type = V_66 ;
return 0 ;
}
int F_25 ( struct V_38 * V_38 , void * V_67 , struct V_40 * V_44 )
{
struct V_7 * V_8 = F_22 ( V_38 ) ;
struct V_68 * V_43 = & V_44 -> V_44 . V_69 ;
if ( ! F_3 ( V_8 ) || ! V_8 -> V_70 )
return - V_15 ;
F_26 ( V_43 , V_8 -> V_71 ) ;
return 0 ;
}
int F_27 ( struct V_38 * V_38 , void * V_67 , struct V_40 * V_44 )
{
struct V_7 * V_8 = F_22 ( V_38 ) ;
struct V_68 * V_43 = & V_44 -> V_44 . V_69 ;
bool V_9 = V_8 -> V_10 & V_11 ;
T_1 V_72 = V_43 -> V_72 ;
if ( ! F_3 ( V_8 ) || ! V_8 -> V_70 )
return - V_15 ;
V_72 &= V_9 ? V_73 :
V_74 | V_75 ;
F_26 ( V_43 , V_72 ) ;
return 0 ;
}
int F_28 ( struct V_38 * V_38 , void * V_67 ,
struct V_40 * V_44 )
{
struct V_7 * V_8 = F_22 ( V_38 ) ;
struct V_68 * V_43 = & V_44 -> V_44 . V_69 ;
int V_60 = F_27 ( V_38 , V_67 , V_44 ) ;
if ( V_60 )
return V_60 ;
if ( F_24 ( & V_8 -> V_61 ) )
return - V_62 ;
V_8 -> V_71 = V_43 -> V_72 ;
V_8 -> V_63 = true ;
V_8 -> V_64 . V_65 -> type = V_13 ;
return 0 ;
}
void F_29 ( struct V_7 * V_8 ,
struct V_23 * V_24 )
{
struct V_14 * V_43 =
F_30 ( & V_24 -> V_18 . V_34 , 0 ) ;
unsigned V_76 =
F_31 ( & V_24 -> V_18 . V_34 , 0 ) / sizeof( * V_43 ) ;
V_8 -> V_37 [ 0 ] = false ;
V_8 -> V_37 [ 1 ] = false ;
V_8 -> V_36 = false ;
while ( V_76 -- ) {
switch ( V_43 -> V_77 ) {
case V_73 :
if ( ( V_8 -> V_10 & V_11 ) && V_43 -> line == 21 ) {
V_8 -> V_37 [ ! ! V_43 -> V_78 ] = true ;
V_8 -> V_79 [ ! ! V_43 -> V_78 ] [ 0 ] = V_43 -> V_80 [ 0 ] ;
V_8 -> V_79 [ ! ! V_43 -> V_78 ] [ 1 ] = V_43 -> V_80 [ 1 ] ;
}
break;
case V_74 :
if ( ( V_8 -> V_10 & V_81 ) &&
V_43 -> V_78 == 0 && V_43 -> line == 23 ) {
V_8 -> V_36 = true ;
V_8 -> V_82 [ 0 ] = V_43 -> V_80 [ 0 ] ;
V_8 -> V_82 [ 1 ] = V_43 -> V_80 [ 1 ] ;
}
break;
}
V_43 ++ ;
}
}
