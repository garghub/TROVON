static void F_1 ( struct V_1 * V_2 ,
enum V_3 type ,
union V_4 * V_5 )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
F_2 ( & V_2 -> V_9 , V_8 ) ;
V_7 = & ( V_2 -> V_10 [ V_2 -> V_11 ] ) ;
V_2 -> V_11 = ( V_2 -> V_11 + 1 ) % V_12 ;
V_7 -> V_13 = V_14 ;
V_7 -> V_15 = V_2 -> V_16 ++ ;
V_7 -> type = type ;
V_7 -> V_5 = * V_5 ;
F_3 ( & V_2 -> V_9 , V_8 ) ;
F_4 ( & V_2 -> V_17 ) ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
union V_4 V_20 ;
V_20 . V_21 = V_19 -> V_21 ;
memcpy ( & V_20 . V_22 , V_19 , sizeof( struct V_18 ) ) ;
F_1 ( V_2 , V_23 , & V_20 ) ;
}
void F_6 ( struct V_1 * V_2 ,
int V_24 , int V_25 )
{
union V_4 V_20 ;
V_20 . V_24 = V_24 ;
V_20 . V_25 = V_25 ;
F_1 ( V_2 , V_26 , & V_20 ) ;
}
void F_7 ( struct V_1 * V_2 ,
int V_24 , int V_25 )
{
union V_4 V_20 ;
V_20 . V_24 = V_24 ;
V_20 . V_25 = V_25 ;
F_1 ( V_2 , V_27 , & V_20 ) ;
}
void F_8 ( struct V_1 * V_2 ,
T_1 V_28 , T_1 V_29 ,
T_1 V_30 , T_1 V_31 )
{
union V_4 V_20 ;
V_20 . V_28 = V_28 ;
V_20 . V_29 = V_29 ;
V_20 . V_30 = V_30 ;
V_20 . V_31 = V_31 ;
F_1 ( V_2 , V_32 , & V_20 ) ;
}
static int F_9 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_1 * V_38 = & V_36 -> V_38 ;
struct V_39 * V_40 ;
unsigned long V_8 ;
V_40 = F_10 ( sizeof( * V_40 ) , V_41 ) ;
if ( V_40 == NULL )
return - V_42 ;
F_2 ( & V_38 -> V_9 , V_8 ) ;
V_40 -> V_11 = V_38 -> V_11 ;
V_40 -> V_38 = V_38 ;
F_3 ( & V_38 -> V_9 , V_8 ) ;
V_34 -> V_43 = V_40 ;
return 0 ;
}
static int F_11 ( struct V_33 * V_33 ,
struct V_34 * V_34 )
{
struct V_39 * V_40 = V_34 -> V_43 ;
F_12 ( V_40 ) ;
return 0 ;
}
static unsigned int F_13 ( struct V_34 * V_34 ,
T_2 * V_44 )
{
struct V_39 * V_40 = V_34 -> V_43 ;
F_14 ( V_34 , & V_40 -> V_38 -> V_17 , V_44 ) ;
return V_45 | V_46 ;
}
static T_3 F_15 ( struct V_34 * V_34 , char T_4 * V_2 ,
T_5 V_47 , T_6 * V_48 )
{
struct V_39 * V_40 = V_34 -> V_43 ;
struct V_1 * V_38 = V_40 -> V_38 ;
struct V_6 * V_7 ;
char V_49 [ V_50 ] ;
int V_51 ;
int V_52 ;
unsigned long V_8 ;
if ( V_38 -> V_11 == V_40 -> V_11 ) {
if ( V_34 -> V_53 & V_54 )
return - V_55 ;
V_51 = F_16 ( V_38 -> V_17 ,
V_38 -> V_11 != V_40 -> V_11 ) ;
if ( V_51 )
return V_51 ;
}
F_2 ( & V_38 -> V_9 , V_8 ) ;
V_7 = & ( V_38 -> V_10 [ V_40 -> V_11 ] ) ;
V_40 -> V_11 = ( V_40 -> V_11 + 1 ) %
V_12 ;
V_47 = V_47 < V_50 ?
V_47 : V_50 ;
V_52 = F_17 ( V_49 , V_47 , L_1 , V_7 -> V_15 , V_7 -> V_13 ) ;
switch ( V_7 -> type ) {
case V_23 :
V_52 += F_17 ( V_49 + V_52 , V_47 - V_52 , L_2 ,
! ( V_7 -> V_5 . V_21 & V_56 ) ,
V_7 -> V_5 . V_22 . V_8 . V_57 [ 0 ] . V_58 ) ;
break;
case V_26 :
V_52 += F_17 ( V_49 + V_52 , V_47 - V_52 , L_3 ,
V_7 -> V_5 . V_24 , V_7 -> V_5 . V_25 ) ;
break;
case V_27 :
V_52 += F_17 ( V_49 + V_52 , V_47 - V_52 , L_4 ,
V_7 -> V_5 . V_24 , V_7 -> V_5 . V_25 ) ;
break;
case V_32 :
V_52 += F_17 ( V_49 + V_52 , V_47 - V_52 ,
L_5 ,
V_7 -> V_5 . V_28 , V_7 -> V_5 . V_29 ,
V_7 -> V_5 . V_30 , V_7 -> V_5 . V_31 ) ;
break;
}
V_52 += F_17 ( V_49 + V_52 , V_47 - V_52 , L_6 ) ;
F_3 ( & V_38 -> V_9 , V_8 ) ;
if ( F_18 ( V_2 , V_49 , V_52 ) )
return - V_59 ;
return V_52 ;
}
void F_19 ( void * V_60 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_35 * V_64 = V_61 ;
V_64 -> V_65 = F_20 ( L_7 , V_66 ,
V_63 , V_64 ,
& V_67 ) ;
}
void F_21 ( void * V_60 , void * V_61 )
{
struct V_35 * V_64 = V_61 ;
F_22 ( V_64 -> V_65 ) ;
}
