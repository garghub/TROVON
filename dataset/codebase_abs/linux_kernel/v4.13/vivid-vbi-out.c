static int F_1 ( struct V_1 * V_2 ,
unsigned * V_3 , unsigned * V_4 ,
unsigned V_5 [] , struct V_6 * V_7 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
bool V_10 = V_9 -> V_11 & V_12 ;
unsigned V_13 = V_2 -> type == V_14 ?
36 * sizeof( struct V_15 ) :
1440 * 2 * ( V_10 ? 12 : 18 ) ;
if ( ! F_3 ( V_9 ) )
return - V_16 ;
V_5 [ 0 ] = V_13 ;
if ( V_2 -> V_17 + * V_3 < 2 )
* V_3 = 2 - V_2 -> V_17 ;
* V_4 = 1 ;
return 0 ;
}
static int F_4 ( struct V_18 * V_19 )
{
struct V_8 * V_9 = F_2 ( V_19 -> V_1 ) ;
bool V_10 = V_9 -> V_11 & V_12 ;
unsigned V_13 = V_19 -> V_1 -> type == V_14 ?
36 * sizeof( struct V_15 ) :
1440 * 2 * ( V_10 ? 12 : 18 ) ;
F_5 ( V_9 , 1 , L_1 , V_20 ) ;
if ( V_9 -> V_21 ) {
V_9 -> V_21 = false ;
return - V_16 ;
}
if ( F_6 ( V_19 , 0 ) < V_13 ) {
F_5 ( V_9 , 1 , L_2 ,
V_20 , F_6 ( V_19 , 0 ) , V_13 ) ;
return - V_16 ;
}
F_7 ( V_19 , 0 , V_13 ) ;
return 0 ;
}
static void F_8 ( struct V_18 * V_19 )
{
struct V_22 * V_23 = F_9 ( V_19 ) ;
struct V_8 * V_9 = F_2 ( V_19 -> V_1 ) ;
struct V_24 * V_25 = F_10 ( V_23 , struct V_24 , V_19 ) ;
F_5 ( V_9 , 1 , L_1 , V_20 ) ;
F_11 ( & V_9 -> V_26 ) ;
F_12 ( & V_25 -> V_27 , & V_9 -> V_28 ) ;
F_13 ( & V_9 -> V_26 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_29 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_30 ;
F_5 ( V_9 , 1 , L_1 , V_20 ) ;
V_9 -> V_31 = 0 ;
if ( V_9 -> V_32 ) {
V_9 -> V_32 = false ;
V_30 = - V_16 ;
} else {
V_30 = F_15 ( V_9 , & V_9 -> V_33 ) ;
}
if ( V_30 ) {
struct V_24 * V_25 , * V_34 ;
F_16 (buf, tmp, &dev->vbi_out_active, list) {
F_17 ( & V_25 -> V_27 ) ;
F_18 ( & V_25 -> V_19 . V_35 ,
V_36 ) ;
}
}
return V_30 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_5 ( V_9 , 1 , L_1 , V_20 ) ;
F_20 ( V_9 , & V_9 -> V_33 ) ;
V_9 -> V_37 = false ;
V_9 -> V_38 [ 0 ] = false ;
V_9 -> V_38 [ 1 ] = false ;
}
int F_21 ( struct V_39 * V_39 , void * V_40 ,
struct V_41 * V_42 )
{
struct V_8 * V_9 = F_22 ( V_39 ) ;
struct V_43 * V_44 = & V_42 -> V_45 . V_44 ;
bool V_10 = V_9 -> V_11 & V_12 ;
if ( ! F_3 ( V_9 ) || ! V_9 -> V_46 )
return - V_16 ;
V_44 -> V_47 = 25000000 ;
V_44 -> V_48 = 24 ;
V_44 -> V_49 = 1440 ;
V_44 -> V_50 = V_51 ;
V_44 -> V_52 [ 0 ] = V_10 ? V_53 + 9 : V_54 + 5 ;
V_44 -> V_52 [ 1 ] = V_10 ? V_55 + 9 : V_56 + 5 ;
V_44 -> V_29 [ 0 ] = V_44 -> V_29 [ 1 ] = V_10 ? 12 : 18 ;
V_44 -> V_57 = V_9 -> V_58 ? V_59 : 0 ;
V_44 -> V_60 [ 0 ] = 0 ;
V_44 -> V_60 [ 1 ] = 0 ;
return 0 ;
}
int F_23 ( struct V_39 * V_39 , void * V_40 ,
struct V_41 * V_42 )
{
struct V_8 * V_9 = F_22 ( V_39 ) ;
int V_61 = F_21 ( V_39 , V_40 , V_42 ) ;
if ( V_61 )
return V_61 ;
if ( F_24 ( & V_9 -> V_62 ) )
return - V_63 ;
V_9 -> V_64 = false ;
V_9 -> V_65 . V_66 -> type = V_67 ;
return 0 ;
}
int F_25 ( struct V_39 * V_39 , void * V_68 , struct V_41 * V_45 )
{
struct V_8 * V_9 = F_22 ( V_39 ) ;
struct V_69 * V_44 = & V_45 -> V_45 . V_70 ;
if ( ! F_3 ( V_9 ) || ! V_9 -> V_71 )
return - V_16 ;
F_26 ( V_44 , V_9 -> V_72 ) ;
return 0 ;
}
int F_27 ( struct V_39 * V_39 , void * V_68 , struct V_41 * V_45 )
{
struct V_8 * V_9 = F_22 ( V_39 ) ;
struct V_69 * V_44 = & V_45 -> V_45 . V_70 ;
bool V_10 = V_9 -> V_11 & V_12 ;
T_1 V_73 = V_44 -> V_73 ;
if ( ! F_3 ( V_9 ) || ! V_9 -> V_71 )
return - V_16 ;
V_73 &= V_10 ? V_74 :
V_75 | V_76 ;
F_26 ( V_44 , V_73 ) ;
return 0 ;
}
int F_28 ( struct V_39 * V_39 , void * V_68 ,
struct V_41 * V_45 )
{
struct V_8 * V_9 = F_22 ( V_39 ) ;
struct V_69 * V_44 = & V_45 -> V_45 . V_70 ;
int V_61 = F_27 ( V_39 , V_68 , V_45 ) ;
if ( V_61 )
return V_61 ;
if ( F_24 ( & V_9 -> V_62 ) )
return - V_63 ;
V_9 -> V_72 = V_44 -> V_73 ;
V_9 -> V_64 = true ;
V_9 -> V_65 . V_66 -> type = V_14 ;
return 0 ;
}
void F_29 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
struct V_15 * V_44 =
F_30 ( & V_25 -> V_19 . V_35 , 0 ) ;
unsigned V_77 =
F_31 ( & V_25 -> V_19 . V_35 , 0 ) / sizeof( * V_44 ) ;
V_9 -> V_38 [ 0 ] = false ;
V_9 -> V_38 [ 1 ] = false ;
V_9 -> V_37 = false ;
while ( V_77 -- ) {
switch ( V_44 -> V_78 ) {
case V_74 :
if ( ( V_9 -> V_11 & V_12 ) && V_44 -> line == 21 ) {
V_9 -> V_38 [ ! ! V_44 -> V_79 ] = true ;
V_9 -> V_80 [ ! ! V_44 -> V_79 ] [ 0 ] = V_44 -> V_81 [ 0 ] ;
V_9 -> V_80 [ ! ! V_44 -> V_79 ] [ 1 ] = V_44 -> V_81 [ 1 ] ;
}
break;
case V_75 :
if ( ( V_9 -> V_11 & V_82 ) &&
V_44 -> V_79 == 0 && V_44 -> line == 23 ) {
V_9 -> V_37 = true ;
V_9 -> V_83 [ 0 ] = V_44 -> V_81 [ 0 ] ;
V_9 -> V_83 [ 1 ] = V_44 -> V_81 [ 1 ] ;
}
break;
}
V_44 ++ ;
}
}
