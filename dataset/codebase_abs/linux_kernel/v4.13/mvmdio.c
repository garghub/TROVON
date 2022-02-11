static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_8 = F_2 ( V_9 ) ;
unsigned long V_10 = V_11 + V_8 ;
int V_12 = 0 ;
while ( 1 ) {
if ( V_2 -> V_13 ( V_6 ) )
return 0 ;
else if ( V_12 )
break;
if ( V_6 -> V_14 <= 0 ) {
F_3 ( V_2 -> V_15 ,
V_2 -> V_16 ) ;
if ( F_4 ( V_10 ) )
++ V_12 ;
} else {
if ( V_8 < 2 )
V_8 = 2 ;
F_5 ( V_6 -> V_17 ,
V_2 -> V_13 ( V_6 ) , V_8 ) ;
++ V_12 ;
}
}
F_6 ( V_4 -> V_18 , L_1 ) ;
return - V_19 ;
}
static int F_7 ( struct V_5 * V_6 )
{
return ! ( F_8 ( V_6 -> V_20 ) & V_21 ) ;
}
static int F_9 ( struct V_3 * V_4 , int V_22 ,
int V_23 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_24 ;
int V_25 ;
if ( V_23 & V_26 )
return - V_27 ;
V_25 = F_1 ( & V_28 , V_4 ) ;
if ( V_25 < 0 )
return V_25 ;
F_10 ( ( ( V_22 << V_29 ) |
( V_23 << V_30 ) |
V_31 ) ,
V_6 -> V_20 ) ;
V_25 = F_1 ( & V_28 , V_4 ) ;
if ( V_25 < 0 )
return V_25 ;
V_24 = F_8 ( V_6 -> V_20 ) ;
if ( ! ( V_24 & V_32 ) ) {
F_6 ( V_4 -> V_18 , L_2 ) ;
return - V_33 ;
}
return V_24 & F_11 ( 15 , 0 ) ;
}
static int F_12 ( struct V_3 * V_4 , int V_22 ,
int V_23 , T_2 V_34 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_25 ;
if ( V_23 & V_26 )
return - V_27 ;
V_25 = F_1 ( & V_28 , V_4 ) ;
if ( V_25 < 0 )
return V_25 ;
F_10 ( ( ( V_22 << V_29 ) |
( V_23 << V_30 ) |
V_35 |
( V_34 << V_36 ) ) ,
V_6 -> V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 )
{
return ! ( F_8 ( V_6 -> V_20 + V_37 ) & V_38 ) ;
}
static int F_14 ( struct V_3 * V_4 , int V_22 ,
int V_23 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_39 = ( V_23 >> 16 ) & F_11 ( 4 , 0 ) ;
int V_25 ;
if ( ! ( V_23 & V_26 ) )
return - V_27 ;
V_25 = F_1 ( & V_40 , V_4 ) ;
if ( V_25 < 0 )
return V_25 ;
F_10 ( V_23 & F_11 ( 15 , 0 ) , V_6 -> V_20 + V_41 ) ;
F_10 ( ( V_22 << V_42 ) |
( V_39 << V_43 ) |
V_44 ,
V_6 -> V_20 + V_37 ) ;
V_25 = F_1 ( & V_40 , V_4 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! ( F_8 ( V_6 -> V_20 + V_37 ) &
V_45 ) ) {
F_6 ( V_4 -> V_18 , L_3 ) ;
return - V_33 ;
}
return F_8 ( V_6 -> V_20 + V_37 ) & F_11 ( 15 , 0 ) ;
}
static int F_15 ( struct V_3 * V_4 , int V_22 ,
int V_23 , T_2 V_34 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_39 = ( V_23 >> 16 ) & F_11 ( 4 , 0 ) ;
int V_25 ;
if ( ! ( V_23 & V_26 ) )
return - V_27 ;
V_25 = F_1 ( & V_40 , V_4 ) ;
if ( V_25 < 0 )
return V_25 ;
F_10 ( V_23 & F_11 ( 15 , 0 ) , V_6 -> V_20 + V_41 ) ;
F_10 ( ( V_22 << V_42 ) |
( V_39 << V_43 ) |
V_46 | V_34 ,
V_6 -> V_20 + V_37 ) ;
return 0 ;
}
static T_3 F_16 ( int V_47 , void * V_48 )
{
struct V_5 * V_6 = V_48 ;
if ( F_8 ( V_6 -> V_20 + V_49 ) &
V_50 ) {
F_10 ( ~ V_50 ,
V_6 -> V_20 + V_49 ) ;
F_17 ( & V_6 -> V_17 ) ;
return V_51 ;
}
return V_52 ;
}
static int F_18 ( struct V_53 * V_54 )
{
enum V_55 type ;
struct V_56 * V_57 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_58 , V_25 ;
type = (enum V_55 ) F_19 ( & V_54 -> V_6 ) ;
V_57 = F_20 ( V_54 , V_59 , 0 ) ;
if ( ! V_57 ) {
F_6 ( & V_54 -> V_6 , L_4 ) ;
return - V_33 ;
}
V_4 = F_21 ( & V_54 -> V_6 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return - V_60 ;
switch ( type ) {
case V_61 :
V_4 -> V_62 = F_9 ;
V_4 -> V_63 = F_12 ;
break;
case V_64 :
V_4 -> V_62 = F_14 ;
V_4 -> V_63 = F_15 ;
break;
}
V_4 -> V_65 = L_5 ;
snprintf ( V_4 -> V_66 , V_67 , L_6 ,
F_22 ( & V_54 -> V_6 ) ) ;
V_4 -> V_18 = & V_54 -> V_6 ;
V_6 = V_4 -> V_7 ;
V_6 -> V_20 = F_23 ( & V_54 -> V_6 , V_57 -> V_68 , F_24 ( V_57 ) ) ;
if ( ! V_6 -> V_20 ) {
F_6 ( & V_54 -> V_6 , L_7 ) ;
return - V_33 ;
}
F_25 ( & V_6 -> V_17 ) ;
for ( V_58 = 0 ; V_58 < F_26 ( V_6 -> V_69 ) ; V_58 ++ ) {
V_6 -> V_69 [ V_58 ] = F_27 ( V_54 -> V_6 . V_70 , V_58 ) ;
if ( F_28 ( V_6 -> V_69 [ V_58 ] ) )
break;
F_29 ( V_6 -> V_69 [ V_58 ] ) ;
}
V_6 -> V_14 = F_30 ( V_54 , 0 ) ;
if ( V_6 -> V_14 > 0 &&
F_24 ( V_57 ) < V_71 + 4 ) {
F_6 ( & V_54 -> V_6 ,
L_8 ) ;
V_6 -> V_14 = 0 ;
}
if ( V_6 -> V_14 > 0 ) {
V_25 = F_31 ( & V_54 -> V_6 , V_6 -> V_14 ,
F_16 ,
V_72 , V_54 -> V_65 , V_6 ) ;
if ( V_25 )
goto V_73;
F_10 ( V_50 ,
V_6 -> V_20 + V_71 ) ;
} else if ( V_6 -> V_14 == - V_74 ) {
return - V_74 ;
}
if ( V_54 -> V_6 . V_70 )
V_25 = F_32 ( V_4 , V_54 -> V_6 . V_70 ) ;
else
V_25 = F_33 ( V_4 ) ;
if ( V_25 < 0 ) {
F_6 ( & V_54 -> V_6 , L_9 , V_25 ) ;
goto V_73;
}
F_34 ( V_54 , V_4 ) ;
return 0 ;
V_73:
if ( V_6 -> V_14 > 0 )
F_10 ( 0 , V_6 -> V_20 + V_71 ) ;
for ( V_58 = 0 ; V_58 < F_26 ( V_6 -> V_69 ) ; V_58 ++ ) {
if ( F_28 ( V_6 -> V_69 [ V_58 ] ) )
break;
F_35 ( V_6 -> V_69 [ V_58 ] ) ;
F_36 ( V_6 -> V_69 [ V_58 ] ) ;
}
return V_25 ;
}
static int F_37 ( struct V_53 * V_54 )
{
struct V_3 * V_4 = F_38 ( V_54 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_58 ;
if ( V_6 -> V_14 > 0 )
F_10 ( 0 , V_6 -> V_20 + V_71 ) ;
F_39 ( V_4 ) ;
for ( V_58 = 0 ; V_58 < F_26 ( V_6 -> V_69 ) ; V_58 ++ ) {
if ( F_28 ( V_6 -> V_69 [ V_58 ] ) )
break;
F_35 ( V_6 -> V_69 [ V_58 ] ) ;
F_36 ( V_6 -> V_69 [ V_58 ] ) ;
}
return 0 ;
}
