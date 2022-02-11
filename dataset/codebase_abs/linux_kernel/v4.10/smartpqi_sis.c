int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
V_3 = ( V_5 * V_6 ) + V_7 ;
while ( 1 ) {
V_4 = F_2 ( & V_2 -> V_8 -> V_9 ) ;
if ( V_4 != ~ 0 ) {
if ( V_4 & V_10 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_1 ,
F_2 (
& V_2 -> V_8 -> V_13 [ 7 ] ) ) ;
return - V_14 ;
}
if ( V_4 & V_15 )
break;
}
if ( F_4 ( V_7 , V_3 ) )
return - V_16 ;
F_5 ( V_17 ) ;
}
return 0 ;
}
bool F_6 ( struct V_1 * V_2 )
{
bool V_18 ;
T_1 V_4 ;
V_4 = F_2 ( & V_2 -> V_8 -> V_9 ) ;
if ( V_4 & V_10 )
V_18 = false ;
else
V_18 = true ;
if ( ! V_18 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_1 ,
F_2 ( & V_2 -> V_8 -> V_13 [ 7 ] ) ) ;
return V_18 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_19 , struct V_20 * V_21 )
{
struct V_22 T_2 * V_8 ;
unsigned int V_23 ;
unsigned long V_3 ;
T_1 V_24 ;
T_1 V_25 ;
V_8 = V_2 -> V_8 ;
F_8 ( V_19 , & V_8 -> V_13 [ 0 ] ) ;
for ( V_23 = 1 ; V_23 <= 4 ; V_23 ++ )
F_8 ( V_21 -> V_26 [ V_23 ] , & V_8 -> V_13 [ V_23 ] ) ;
F_8 ( V_27 ,
& V_8 -> V_28 ) ;
F_8 ( ~ 0 , & V_8 -> V_29 ) ;
F_2 ( & V_8 -> V_29 ) ;
F_8 ( V_30 , & V_8 -> V_31 ) ;
V_3 = ( V_32 * V_6 ) + V_7 ;
while ( 1 ) {
F_5 ( V_33 ) ;
V_24 = F_2 ( & V_8 -> V_34 ) ;
if ( V_24 & V_35 )
break;
if ( F_4 ( V_7 , V_3 ) )
return - V_16 ;
}
V_25 = F_2 ( & V_8 -> V_13 [ 0 ] ) ;
if ( V_25 != V_36 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_2 ,
V_19 , V_25 ) ;
return - V_37 ;
}
V_21 -> V_26 [ 0 ] = V_25 ;
for ( V_23 = 1 ; V_23 < F_9 ( V_21 -> V_26 ) ; V_23 ++ )
V_21 -> V_26 [ V_23 ] = F_2 ( & V_8 -> V_13 [ V_23 ] ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_38 ;
T_1 V_39 ;
T_1 V_40 ;
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_38 = F_7 ( V_2 , V_41 ,
& V_21 ) ;
if ( V_38 )
return V_38 ;
V_39 = V_21 . V_26 [ 1 ] ;
if ( ! ( V_39 & V_42 ) )
return - V_14 ;
V_40 = V_21 . V_26 [ 4 ] ;
if ( ( V_40 & V_43 ) !=
V_43 )
return - V_14 ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_38 ;
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_38 = F_7 ( V_2 , V_44 ,
& V_21 ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_45 = V_21 . V_26 [ 1 ] ;
V_2 -> V_46 = V_21 . V_26 [ 2 ] ;
V_2 -> V_47 = V_21 . V_26 [ 3 ] ;
V_2 -> V_48 = V_21 . V_26 [ 4 ] ;
V_2 -> V_49 = V_21 . V_26 [ 5 ] ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_38 ;
void * V_50 ;
struct V_51 * V_52 ;
struct V_20 V_21 ;
unsigned long V_53 ;
T_3 V_54 ;
V_50 = F_13 ( sizeof( * V_52 )
+ V_55 - 1 , V_56 ) ;
if ( ! V_50 )
return - V_57 ;
V_52 = F_14 ( V_50 ,
V_55 ) ;
V_53 = ( unsigned long ) V_2 -> V_58 ;
F_15 ( V_59 , & V_52 -> V_60 ) ;
F_15 ( F_16 ( V_53 ) ,
& V_52 -> V_61 ) ;
F_15 ( F_17 ( V_53 ) ,
& V_52 -> V_62 ) ;
F_15 ( V_63 ,
& V_52 -> V_64 ) ;
F_15 ( V_2 -> V_65 ,
& V_52 -> V_66 ) ;
V_54 = F_18 ( V_2 -> V_11 , V_52 ,
sizeof( * V_52 ) , V_67 ) ;
if ( F_19 ( V_2 -> V_11 , V_54 ) ) {
V_38 = - V_57 ;
goto V_68;
}
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_26 [ 1 ] = F_16 ( ( V_69 ) V_54 ) ;
V_21 . V_26 [ 2 ] = F_17 ( ( V_69 ) V_54 ) ;
V_21 . V_26 [ 3 ] = sizeof( * V_52 ) ;
V_38 = F_7 ( V_2 , V_70 ,
& V_21 ) ;
F_20 ( V_2 -> V_11 , V_54 , sizeof( * V_52 ) ,
V_67 ) ;
V_68:
F_21 ( V_50 ) ;
return V_38 ;
}
void F_22 ( struct V_1 * V_2 )
{
T_1 V_71 ;
V_71 =
F_2 ( & V_2 -> V_8 -> V_31 ) ;
V_71 |= V_72 ;
F_8 ( V_71 ,
& V_2 -> V_8 -> V_31 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
T_1 V_71 ;
V_71 =
F_2 ( & V_2 -> V_8 -> V_31 ) ;
V_71 &= ~ V_72 ;
F_8 ( V_71 ,
& V_2 -> V_8 -> V_31 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_8 ( V_73 ,
& V_2 -> V_8 -> V_31 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_38 ;
unsigned long V_3 ;
struct V_22 T_2 * V_8 ;
T_1 V_24 ;
V_8 = V_2 -> V_8 ;
F_8 ( V_74 ,
& V_8 -> V_31 ) ;
V_38 = 0 ;
V_3 = ( V_75 * V_6 ) + V_7 ;
while ( 1 ) {
V_24 = F_2 ( & V_8 -> V_34 ) ;
if ( ( V_24 & V_74 ) == 0 )
break;
if ( F_4 ( V_7 , V_3 ) ) {
V_38 = - V_16 ;
break;
}
}
if ( V_38 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_3 ) ;
return V_38 ;
}
void F_26 ( struct V_1 * V_2 , T_1 V_76 )
{
F_8 ( V_76 , & V_2 -> V_8 -> V_77 ) ;
}
T_1 F_27 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_8 -> V_77 ) ;
}
