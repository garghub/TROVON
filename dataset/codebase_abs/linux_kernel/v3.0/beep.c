void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 && V_4 -> V_5 ) {
V_4 -> V_5 = 0 ;
F_2 ( V_2 ) ;
}
}
static int F_3 ( struct V_6 * V_7 , unsigned int type ,
unsigned int V_8 , int V_9 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned long V_10 ;
int V_11 = 0 ;
int V_12 ;
int V_13 , V_14 , V_15 ;
int V_16 , V_17 , V_18 ;
short * V_19 ;
if ( type != V_20 )
return - 1 ;
switch ( V_8 ) {
case V_21 : if ( V_9 ) V_9 = 1000 ;
case V_22 : break;
default: return - 1 ;
}
V_2 = F_4 ( V_7 ) ;
if ( ! V_2 || ( V_4 = V_2 -> V_4 ) == NULL )
return - 1 ;
if ( ! V_9 ) {
F_5 ( & V_2 -> V_23 , V_10 ) ;
if ( V_4 -> V_5 )
F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_23 , V_10 ) ;
return 0 ;
}
V_11 = F_7 ( V_2 , & V_2 -> V_24 , V_25 ) ;
V_12 = V_2 -> V_26 [ V_11 ] ;
if ( V_9 <= V_12 / V_27 || V_9 > V_12 / 2 )
V_9 = 1000 ;
F_5 ( & V_2 -> V_23 , V_10 ) ;
if ( V_2 -> V_24 . V_5 || V_2 -> V_28 . V_5 || V_4 -> V_5 ) {
F_6 ( & V_2 -> V_23 , V_10 ) ;
return 0 ;
}
V_4 -> V_5 = 1 ;
F_6 ( & V_2 -> V_23 , V_10 ) ;
if ( V_9 == V_4 -> V_9 && V_4 -> V_29 == V_4 -> V_30 ) {
V_15 = V_4 -> V_15 ;
} else {
V_13 = V_12 * 256 / V_9 ;
V_14 = V_27 * 256 / V_13 ;
V_15 = ( V_13 * V_14 ) >> 8 ;
V_18 = V_14 * 65536 / V_15 ;
V_17 = 0 ;
V_19 = V_4 -> V_31 ;
for ( V_16 = 0 ; V_16 < V_15 ; ++ V_16 , V_19 += 2 ) {
V_19 [ 0 ] = V_19 [ 1 ] = V_32 [ V_17 >> 8 ] * V_4 -> V_29 ;
V_17 = ( V_17 + V_18 ) & 0xffff ;
}
V_4 -> V_9 = V_9 ;
V_4 -> V_30 = V_4 -> V_29 ;
V_4 -> V_15 = V_15 ;
}
F_5 ( & V_2 -> V_23 , V_10 ) ;
F_8 ( V_2 , V_4 -> V_15 * 4 , V_4 -> V_33 , V_11 ) ;
F_6 ( & V_2 -> V_23 , V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
V_37 -> type = V_38 ;
V_37 -> V_39 = 1 ;
V_37 -> V_40 . integer . V_41 = 0 ;
V_37 -> V_40 . integer . V_42 = 100 ;
return 0 ;
}
static int F_10 ( struct V_34 * V_35 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
if ( F_12 ( ! V_2 -> V_4 ) )
return - V_45 ;
V_44 -> V_40 . integer . V_40 [ 0 ] = V_2 -> V_4 -> V_29 ;
return 0 ;
}
static int F_13 ( struct V_34 * V_35 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
unsigned int V_46 , V_47 ;
if ( F_12 ( ! V_2 -> V_4 ) )
return - V_45 ;
V_46 = V_2 -> V_4 -> V_29 ;
V_47 = V_44 -> V_40 . integer . V_40 [ 0 ] ;
if ( V_47 > 100 )
return - V_48 ;
V_2 -> V_4 -> V_29 = V_47 ;
return V_46 != V_2 -> V_4 -> V_29 ;
}
int T_1 F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_6 ;
struct V_34 * V_49 ;
void * V_50 ;
int V_51 = - V_52 ;
V_4 = F_15 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return - V_52 ;
V_50 = F_16 ( & V_2 -> V_54 -> V_7 , V_27 * 4 ,
& V_4 -> V_33 , V_53 ) ;
V_6 = F_17 () ;
if ( ! V_50 || ! V_6 )
goto V_55;
V_6 -> V_56 = L_1 ;
V_6 -> V_57 = L_2 ;
V_6 -> V_58 . V_59 = V_60 ;
V_6 -> V_58 . V_61 = 0x001f ;
V_6 -> V_58 . V_62 = 0x0001 ;
V_6 -> V_58 . V_63 = 0x0100 ;
V_6 -> V_64 [ 0 ] = F_18 ( V_20 ) ;
V_6 -> V_65 [ 0 ] = F_18 ( V_21 ) | F_18 ( V_22 ) ;
V_6 -> V_66 = F_3 ;
V_6 -> V_7 . V_67 = & V_2 -> V_54 -> V_7 ;
F_19 ( V_6 , V_2 ) ;
V_4 -> V_7 = V_6 ;
V_4 -> V_31 = V_50 ;
V_4 -> V_29 = V_68 ;
V_4 -> V_5 = 0 ;
V_49 = F_20 ( & V_69 , V_2 ) ;
V_51 = F_21 ( V_2 -> V_70 , V_49 ) ;
if ( V_51 < 0 )
goto V_55;
V_2 -> V_4 = V_4 ;
V_51 = F_22 ( V_4 -> V_7 ) ;
if ( V_51 )
goto V_71;
return 0 ;
V_71: F_23 ( V_2 -> V_70 , V_49 ) ;
V_55: F_24 ( V_6 ) ;
if ( V_50 )
F_25 ( & V_2 -> V_54 -> V_7 , V_27 * 4 ,
V_50 , V_4 -> V_33 ) ;
F_26 ( V_4 ) ;
return V_51 ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
F_28 ( V_2 -> V_4 -> V_7 ) ;
F_25 ( & V_2 -> V_54 -> V_7 , V_27 * 4 ,
V_2 -> V_4 -> V_31 , V_2 -> V_4 -> V_33 ) ;
F_26 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
}
