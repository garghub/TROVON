static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned * V_5 , unsigned * V_6 ,
unsigned V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
bool V_11 = V_10 -> V_12 & V_13 ;
unsigned V_14 = V_2 -> type == V_15 ?
36 * sizeof( struct V_16 ) :
1440 * 2 * ( V_11 ? 12 : 18 ) ;
if ( ! F_3 ( V_10 ) )
return - V_17 ;
V_7 [ 0 ] = V_14 ;
if ( V_2 -> V_18 + * V_5 < 2 )
* V_5 = 2 - V_2 -> V_18 ;
* V_6 = 1 ;
return 0 ;
}
static int F_4 ( struct V_19 * V_20 )
{
struct V_9 * V_10 = F_2 ( V_20 -> V_1 ) ;
bool V_11 = V_10 -> V_12 & V_13 ;
unsigned V_14 = V_20 -> V_1 -> type == V_15 ?
36 * sizeof( struct V_16 ) :
1440 * 2 * ( V_11 ? 12 : 18 ) ;
F_5 ( V_10 , 1 , L_1 , V_21 ) ;
if ( V_10 -> V_22 ) {
V_10 -> V_22 = false ;
return - V_17 ;
}
if ( F_6 ( V_20 , 0 ) < V_14 ) {
F_5 ( V_10 , 1 , L_2 ,
V_21 , F_6 ( V_20 , 0 ) , V_14 ) ;
return - V_17 ;
}
F_7 ( V_20 , 0 , V_14 ) ;
return 0 ;
}
static void F_8 ( struct V_19 * V_20 )
{
struct V_9 * V_10 = F_2 ( V_20 -> V_1 ) ;
struct V_23 * V_24 = F_9 ( V_20 , struct V_23 , V_20 ) ;
F_5 ( V_10 , 1 , L_1 , V_21 ) ;
F_10 ( & V_10 -> V_25 ) ;
F_11 ( & V_24 -> V_26 , & V_10 -> V_27 ) ;
F_12 ( & V_10 -> V_25 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_28 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_29 ;
F_5 ( V_10 , 1 , L_1 , V_21 ) ;
V_10 -> V_30 = 0 ;
if ( V_10 -> V_31 ) {
V_10 -> V_31 = false ;
V_29 = - V_17 ;
} else {
V_29 = F_14 ( V_10 , & V_10 -> V_32 ) ;
}
if ( V_29 ) {
struct V_23 * V_24 , * V_33 ;
F_15 (buf, tmp, &dev->vbi_out_active, list) {
F_16 ( & V_24 -> V_26 ) ;
F_17 ( & V_24 -> V_20 , V_34 ) ;
}
}
return V_29 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_5 ( V_10 , 1 , L_1 , V_21 ) ;
F_19 ( V_10 , & V_10 -> V_32 ) ;
V_10 -> V_35 = false ;
V_10 -> V_36 [ 0 ] = false ;
V_10 -> V_36 [ 1 ] = false ;
}
int F_20 ( struct V_37 * V_37 , void * V_38 ,
struct V_3 * V_39 )
{
struct V_9 * V_10 = F_21 ( V_37 ) ;
struct V_40 * V_41 = & V_39 -> V_4 . V_41 ;
bool V_11 = V_10 -> V_12 & V_13 ;
if ( ! F_3 ( V_10 ) || ! V_10 -> V_42 )
return - V_17 ;
V_41 -> V_43 = 25000000 ;
V_41 -> V_44 = 24 ;
V_41 -> V_45 = 1440 ;
V_41 -> V_46 = V_47 ;
V_41 -> V_48 [ 0 ] = V_11 ? V_49 + 9 : V_50 + 5 ;
V_41 -> V_48 [ 1 ] = V_11 ? V_51 + 9 : V_52 + 5 ;
V_41 -> V_28 [ 0 ] = V_41 -> V_28 [ 1 ] = V_11 ? 12 : 18 ;
V_41 -> V_53 = V_10 -> V_54 ? V_55 : 0 ;
V_41 -> V_56 [ 0 ] = 0 ;
V_41 -> V_56 [ 1 ] = 0 ;
return 0 ;
}
int F_22 ( struct V_37 * V_37 , void * V_38 ,
struct V_3 * V_39 )
{
struct V_9 * V_10 = F_21 ( V_37 ) ;
int V_57 = F_20 ( V_37 , V_38 , V_39 ) ;
if ( V_57 )
return V_57 ;
if ( F_23 ( & V_10 -> V_58 ) )
return - V_59 ;
V_10 -> V_60 = false ;
V_10 -> V_61 . V_62 -> type = V_63 ;
return 0 ;
}
int F_24 ( struct V_37 * V_37 , void * V_64 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_21 ( V_37 ) ;
struct V_65 * V_41 = & V_4 -> V_4 . V_66 ;
if ( ! F_3 ( V_10 ) || ! V_10 -> V_67 )
return - V_17 ;
F_25 ( V_41 , V_10 -> V_68 ) ;
return 0 ;
}
int F_26 ( struct V_37 * V_37 , void * V_64 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_21 ( V_37 ) ;
struct V_65 * V_41 = & V_4 -> V_4 . V_66 ;
bool V_11 = V_10 -> V_12 & V_13 ;
T_1 V_69 = V_41 -> V_69 ;
if ( ! F_3 ( V_10 ) || ! V_10 -> V_67 )
return - V_17 ;
V_69 &= V_11 ? V_70 :
V_71 | V_72 ;
F_25 ( V_41 , V_69 ) ;
return 0 ;
}
int F_27 ( struct V_37 * V_37 , void * V_64 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_21 ( V_37 ) ;
struct V_65 * V_41 = & V_4 -> V_4 . V_66 ;
int V_57 = F_26 ( V_37 , V_64 , V_4 ) ;
if ( V_57 )
return V_57 ;
if ( F_23 ( & V_10 -> V_58 ) )
return - V_59 ;
V_10 -> V_68 = V_41 -> V_69 ;
V_10 -> V_60 = true ;
V_10 -> V_61 . V_62 -> type = V_15 ;
return 0 ;
}
void F_28 ( struct V_9 * V_10 , struct V_23 * V_24 )
{
struct V_16 * V_41 = F_29 ( & V_24 -> V_20 , 0 ) ;
unsigned V_73 = F_30 ( & V_24 -> V_20 , 0 ) / sizeof( * V_41 ) ;
V_10 -> V_36 [ 0 ] = false ;
V_10 -> V_36 [ 1 ] = false ;
V_10 -> V_35 = false ;
while ( V_73 -- ) {
switch ( V_41 -> V_74 ) {
case V_70 :
if ( ( V_10 -> V_12 & V_13 ) && V_41 -> line == 21 ) {
V_10 -> V_36 [ ! ! V_41 -> V_75 ] = true ;
V_10 -> V_76 [ ! ! V_41 -> V_75 ] [ 0 ] = V_41 -> V_77 [ 0 ] ;
V_10 -> V_76 [ ! ! V_41 -> V_75 ] [ 1 ] = V_41 -> V_77 [ 1 ] ;
}
break;
case V_71 :
if ( ( V_10 -> V_12 & V_78 ) &&
V_41 -> V_75 == 0 && V_41 -> line == 23 ) {
V_10 -> V_35 = true ;
V_10 -> V_79 [ 0 ] = V_41 -> V_77 [ 0 ] ;
V_10 -> V_79 [ 1 ] = V_41 -> V_77 [ 1 ] ;
}
break;
}
V_41 ++ ;
}
}
