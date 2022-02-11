int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
return F_2 ( V_4 , V_6 -> V_8 == V_6 -> V_9 ? 1 : 2 ,
V_6 -> V_10 , V_6 -> V_11 ) ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
unsigned int V_16 , V_17 ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_5 ( V_15 , V_6 -> V_20 , & V_18 ) ;
if ( V_19 )
return V_19 ;
V_16 = ( V_18 >> V_6 -> V_8 ) & V_6 -> V_21 ;
V_17 = F_6 ( V_6 , V_16 ) ;
V_13 -> V_22 . V_23 . V_17 [ 0 ] = V_17 ;
if ( V_6 -> V_8 != V_6 -> V_9 ) {
V_16 = ( V_18 >> V_6 -> V_8 ) & V_6 -> V_21 ;
V_17 = F_6 ( V_6 , V_16 ) ;
V_13 -> V_22 . V_23 . V_17 [ 1 ] = V_17 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
unsigned int * V_17 = V_13 -> V_22 . V_23 . V_17 ;
unsigned int V_16 ;
unsigned int V_21 ;
if ( V_17 [ 0 ] >= V_6 -> V_10 )
return - V_24 ;
V_16 = F_8 ( V_6 , V_17 [ 0 ] ) << V_6 -> V_8 ;
V_21 = V_6 -> V_21 << V_6 -> V_8 ;
if ( V_6 -> V_8 != V_6 -> V_9 ) {
if ( V_17 [ 1 ] >= V_6 -> V_10 )
return - V_24 ;
V_16 |= F_8 ( V_6 , V_17 [ 1 ] ) << V_6 -> V_9 ;
V_21 |= V_6 -> V_21 << V_6 -> V_9 ;
}
return F_9 ( V_15 , V_6 -> V_20 , V_21 , V_16 ) ;
}
static int F_10 ( struct V_14 * V_15 ,
unsigned int V_20 , unsigned int V_21 , unsigned int V_25 ,
unsigned int V_26 , int * V_27 )
{
int V_19 ;
unsigned int V_16 ;
V_19 = F_5 ( V_15 , V_20 , & V_16 ) ;
if ( V_19 < 0 )
return V_19 ;
V_16 = ( V_16 >> V_25 ) & V_21 ;
if ( ! V_26 ) {
* V_27 = V_16 ;
return 0 ;
}
if ( ! ( V_16 & F_11 ( V_26 ) ) ) {
* V_27 = V_16 ;
return 0 ;
}
V_19 = V_16 ;
V_19 |= ~ ( ( int ) ( F_11 ( V_26 ) - 1 ) ) ;
* V_27 = V_19 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
int V_30 ;
if ( ! V_29 -> V_30 )
V_29 -> V_30 = V_29 -> V_31 ;
V_30 = V_29 -> V_30 ;
if ( V_30 == 1 && ! strstr ( V_2 -> V_32 . V_33 , L_1 ) )
V_4 -> type = V_34 ;
else
V_4 -> type = V_35 ;
V_4 -> V_36 = F_13 ( V_29 ) ? 2 : 1 ;
V_4 -> V_22 . integer . V_37 = 0 ;
V_4 -> V_22 . integer . V_31 = V_30 - V_29 -> V_37 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
F_12 ( V_2 , V_4 ) ;
V_4 -> V_22 . integer . V_31 += V_29 -> V_37 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
unsigned int V_20 = V_29 -> V_20 ;
unsigned int V_38 = V_29 -> V_39 ;
unsigned int V_25 = V_29 -> V_25 ;
unsigned int V_40 = V_29 -> V_40 ;
int V_31 = V_29 -> V_31 ;
int V_37 = V_29 -> V_37 ;
int V_26 = V_29 -> V_26 ;
unsigned int V_21 = ( 1 << F_16 ( V_31 ) ) - 1 ;
unsigned int V_41 = V_29 -> V_41 ;
int V_16 ;
int V_19 ;
if ( V_26 )
V_21 = F_11 ( V_26 + 1 ) - 1 ;
V_19 = F_10 ( V_15 , V_20 , V_21 , V_25 , V_26 , & V_16 ) ;
if ( V_19 )
return V_19 ;
V_13 -> V_22 . integer . V_22 [ 0 ] = V_16 - V_37 ;
if ( V_41 )
V_13 -> V_22 . integer . V_22 [ 0 ] =
V_31 - V_13 -> V_22 . integer . V_22 [ 0 ] ;
if ( F_13 ( V_29 ) ) {
if ( V_20 == V_38 )
V_19 = F_10 ( V_15 , V_20 , V_21 , V_40 ,
V_26 , & V_16 ) ;
else
V_19 = F_10 ( V_15 , V_38 , V_21 , V_25 ,
V_26 , & V_16 ) ;
if ( V_19 )
return V_19 ;
V_13 -> V_22 . integer . V_22 [ 1 ] = V_16 - V_37 ;
if ( V_41 )
V_13 -> V_22 . integer . V_22 [ 1 ] =
V_31 - V_13 -> V_22 . integer . V_22 [ 1 ] ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
unsigned int V_20 = V_29 -> V_20 ;
unsigned int V_38 = V_29 -> V_39 ;
unsigned int V_25 = V_29 -> V_25 ;
unsigned int V_40 = V_29 -> V_40 ;
int V_31 = V_29 -> V_31 ;
int V_37 = V_29 -> V_37 ;
unsigned int V_26 = V_29 -> V_26 ;
unsigned int V_21 = ( 1 << F_16 ( V_31 ) ) - 1 ;
unsigned int V_41 = V_29 -> V_41 ;
int V_42 ;
bool V_43 = false ;
unsigned int V_44 = 0 ;
unsigned int V_16 , V_45 ;
if ( V_26 )
V_21 = F_11 ( V_26 + 1 ) - 1 ;
V_16 = ( ( V_13 -> V_22 . integer . V_22 [ 0 ] + V_37 ) & V_21 ) ;
if ( V_41 )
V_16 = V_31 - V_16 ;
V_45 = V_21 << V_25 ;
V_16 = V_16 << V_25 ;
if ( F_13 ( V_29 ) ) {
V_44 = ( ( V_13 -> V_22 . integer . V_22 [ 1 ] + V_37 ) & V_21 ) ;
if ( V_41 )
V_44 = V_31 - V_44 ;
if ( V_20 == V_38 ) {
V_45 |= V_21 << V_40 ;
V_16 |= V_44 << V_40 ;
} else {
V_44 = V_44 << V_25 ;
V_43 = true ;
}
}
V_42 = F_9 ( V_15 , V_20 , V_45 , V_16 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_43 )
V_42 = F_9 ( V_15 , V_38 , V_45 ,
V_44 ) ;
return V_42 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
unsigned int V_20 = V_29 -> V_20 ;
unsigned int V_38 = V_29 -> V_39 ;
unsigned int V_25 = V_29 -> V_25 ;
unsigned int V_40 = V_29 -> V_40 ;
int V_31 = V_29 -> V_31 ;
int V_37 = V_29 -> V_37 ;
int V_21 = ( 1 << ( F_16 ( V_37 + V_31 ) - 1 ) ) - 1 ;
unsigned int V_16 ;
int V_19 ;
V_19 = F_5 ( V_15 , V_20 , & V_16 ) ;
if ( V_19 < 0 )
return V_19 ;
V_13 -> V_22 . integer . V_22 [ 0 ] = ( ( V_16 >> V_25 ) - V_37 ) & V_21 ;
if ( F_13 ( V_29 ) ) {
V_19 = F_5 ( V_15 , V_38 , & V_16 ) ;
if ( V_19 < 0 )
return V_19 ;
V_16 = ( ( V_16 >> V_40 ) - V_37 ) & V_21 ;
V_13 -> V_22 . integer . V_22 [ 1 ] = V_16 ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
unsigned int V_20 = V_29 -> V_20 ;
unsigned int V_38 = V_29 -> V_39 ;
unsigned int V_25 = V_29 -> V_25 ;
unsigned int V_40 = V_29 -> V_40 ;
int V_31 = V_29 -> V_31 ;
int V_37 = V_29 -> V_37 ;
int V_21 = ( 1 << ( F_16 ( V_37 + V_31 ) - 1 ) ) - 1 ;
int V_42 = 0 ;
unsigned int V_16 , V_45 , V_44 = 0 ;
V_45 = V_21 << V_25 ;
V_16 = ( V_13 -> V_22 . integer . V_22 [ 0 ] + V_37 ) & V_21 ;
V_16 = V_16 << V_25 ;
V_42 = F_9 ( V_15 , V_20 , V_45 , V_16 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( F_13 ( V_29 ) ) {
V_45 = V_21 << V_40 ;
V_44 = ( V_13 -> V_22 . integer . V_22 [ 1 ] + V_37 ) & V_21 ;
V_44 = V_44 << V_40 ;
V_42 = F_9 ( V_15 , V_38 , V_45 ,
V_44 ) ;
}
return V_42 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
int V_30 ;
int V_37 = V_29 -> V_37 ;
if ( ! V_29 -> V_30 )
V_29 -> V_30 = V_29 -> V_31 ;
V_30 = V_29 -> V_30 ;
V_4 -> type = V_35 ;
V_4 -> V_36 = F_13 ( V_29 ) ? 2 : 1 ;
V_4 -> V_22 . integer . V_37 = 0 ;
V_4 -> V_22 . integer . V_31 = V_30 - V_37 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
struct V_14 * V_15 = F_4 ( V_2 ) ;
unsigned int V_20 = V_29 -> V_20 ;
unsigned int V_39 = V_29 -> V_39 ;
unsigned int V_25 = V_29 -> V_25 ;
int V_37 = V_29 -> V_37 ;
int V_31 = V_29 -> V_31 ;
unsigned int V_21 = ( 1 << F_16 ( V_31 ) ) - 1 ;
unsigned int V_41 = V_29 -> V_41 ;
unsigned int V_16 , V_45 ;
int V_19 ;
if ( V_41 )
V_16 = ( V_31 - V_13 -> V_22 . integer . V_22 [ 0 ] ) & V_21 ;
else
V_16 = ( ( V_13 -> V_22 . integer . V_22 [ 0 ] + V_37 ) & V_21 ) ;
V_45 = V_21 << V_25 ;
V_16 = V_16 << V_25 ;
V_19 = F_9 ( V_15 , V_20 , V_45 , V_16 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( F_13 ( V_29 ) ) {
if ( V_41 )
V_16 = ( V_31 - V_13 -> V_22 . integer . V_22 [ 1 ] ) & V_21 ;
else
V_16 = ( ( V_13 -> V_22 . integer . V_22 [ 1 ] + V_37 ) & V_21 ) ;
V_45 = V_21 << V_25 ;
V_16 = V_16 << V_25 ;
V_19 = F_9 ( V_15 , V_39 , V_45 ,
V_16 ) ;
}
return V_19 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
unsigned int V_20 = V_29 -> V_20 ;
unsigned int V_39 = V_29 -> V_39 ;
unsigned int V_25 = V_29 -> V_25 ;
int V_37 = V_29 -> V_37 ;
int V_31 = V_29 -> V_31 ;
unsigned int V_21 = ( 1 << F_16 ( V_31 ) ) - 1 ;
unsigned int V_41 = V_29 -> V_41 ;
unsigned int V_16 ;
int V_19 ;
V_19 = F_5 ( V_15 , V_20 , & V_16 ) ;
if ( V_19 )
return V_19 ;
V_13 -> V_22 . integer . V_22 [ 0 ] = ( V_16 >> V_25 ) & V_21 ;
if ( V_41 )
V_13 -> V_22 . integer . V_22 [ 0 ] =
V_31 - V_13 -> V_22 . integer . V_22 [ 0 ] ;
else
V_13 -> V_22 . integer . V_22 [ 0 ] =
V_13 -> V_22 . integer . V_22 [ 0 ] - V_37 ;
if ( F_13 ( V_29 ) ) {
V_19 = F_5 ( V_15 , V_39 , & V_16 ) ;
if ( V_19 )
return V_19 ;
V_13 -> V_22 . integer . V_22 [ 1 ] = ( V_16 >> V_25 ) & V_21 ;
if ( V_41 )
V_13 -> V_22 . integer . V_22 [ 1 ] =
V_31 - V_13 -> V_22 . integer . V_22 [ 1 ] ;
else
V_13 -> V_22 . integer . V_22 [ 1 ] =
V_13 -> V_22 . integer . V_22 [ 1 ] - V_37 ;
}
return 0 ;
}
int F_23 ( struct V_46 * V_47 ,
const char * V_33 , int V_31 )
{
struct V_48 * V_48 = V_47 -> V_48 ;
struct V_1 * V_49 ;
struct V_28 * V_29 ;
int V_50 = 0 ;
int V_19 = - V_24 ;
if ( F_24 ( ! V_33 || V_31 <= 0 ) )
return - V_24 ;
F_25 (kctl, &snd_card->controls, list) {
if ( ! strncmp ( V_49 -> V_32 . V_33 , V_33 , sizeof( V_49 -> V_32 . V_33 ) ) ) {
V_50 = 1 ;
break;
}
}
if ( V_50 ) {
V_29 = (struct V_28 * ) V_49 -> V_7 ;
if ( V_31 <= V_29 -> V_31 ) {
V_29 -> V_30 = V_31 ;
V_19 = 0 ;
}
}
return V_19 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_51 * V_52 = ( void * ) V_2 -> V_7 ;
V_4 -> type = V_53 ;
V_4 -> V_36 = V_52 -> V_54 * V_15 -> V_55 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_51 * V_52 = ( void * ) V_2 -> V_7 ;
int V_19 ;
if ( V_15 -> V_56 )
V_19 = F_28 ( V_15 -> V_56 , V_52 -> V_57 ,
V_13 -> V_22 . V_58 . V_59 ,
V_52 -> V_54 * V_15 -> V_55 ) ;
else
V_19 = - V_24 ;
if ( V_19 == 0 && V_52 -> V_21 ) {
switch ( V_15 -> V_55 ) {
case 1 :
V_13 -> V_22 . V_58 . V_59 [ 0 ] &= ~ V_52 -> V_21 ;
break;
case 2 :
( ( V_60 * ) ( & V_13 -> V_22 . V_58 . V_59 ) ) [ 0 ]
&= F_29 ( ~ V_52 -> V_21 ) ;
break;
case 4 :
( ( V_61 * ) ( & V_13 -> V_22 . V_58 . V_59 ) ) [ 0 ]
&= F_30 ( ~ V_52 -> V_21 ) ;
break;
default:
return - V_24 ;
}
}
return V_19 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_51 * V_52 = ( void * ) V_2 -> V_7 ;
int V_19 , V_62 ;
unsigned int V_16 , V_21 ;
void * V_59 ;
if ( ! V_15 -> V_56 || ! V_52 -> V_54 )
return - V_24 ;
V_62 = V_52 -> V_54 * V_15 -> V_55 ;
V_59 = F_32 ( V_13 -> V_22 . V_58 . V_59 , V_62 , V_63 | V_64 ) ;
if ( ! V_59 )
return - V_65 ;
if ( V_52 -> V_21 ) {
V_19 = F_33 ( V_15 -> V_56 , V_52 -> V_57 , & V_16 ) ;
if ( V_19 != 0 )
goto V_66;
V_16 &= V_52 -> V_21 ;
switch ( V_15 -> V_55 ) {
case 1 :
( ( V_67 * ) V_59 ) [ 0 ] &= ~ V_52 -> V_21 ;
( ( V_67 * ) V_59 ) [ 0 ] |= V_16 ;
break;
case 2 :
V_21 = ~ V_52 -> V_21 ;
V_19 = F_34 ( V_15 -> V_56 ,
& V_21 , & V_21 ) ;
if ( V_19 != 0 )
goto V_66;
( ( V_60 * ) V_59 ) [ 0 ] &= V_21 ;
V_19 = F_34 ( V_15 -> V_56 ,
& V_16 , & V_16 ) ;
if ( V_19 != 0 )
goto V_66;
( ( V_60 * ) V_59 ) [ 0 ] |= V_16 ;
break;
case 4 :
V_21 = ~ V_52 -> V_21 ;
V_19 = F_34 ( V_15 -> V_56 ,
& V_21 , & V_21 ) ;
if ( V_19 != 0 )
goto V_66;
( ( V_61 * ) V_59 ) [ 0 ] &= V_21 ;
V_19 = F_34 ( V_15 -> V_56 ,
& V_16 , & V_16 ) ;
if ( V_19 != 0 )
goto V_66;
( ( V_61 * ) V_59 ) [ 0 ] |= V_16 ;
break;
default:
V_19 = - V_24 ;
goto V_66;
}
}
V_19 = F_35 ( V_15 -> V_56 , V_52 -> V_57 ,
V_59 , V_62 ) ;
V_66:
F_36 ( V_59 ) ;
return V_19 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_13 )
{
struct V_68 * V_52 = ( void * ) V_2 -> V_7 ;
V_13 -> type = V_53 ;
V_13 -> V_36 = V_52 -> V_31 ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , int V_69 ,
unsigned int V_70 , unsigned int T_1 * V_71 )
{
struct V_68 * V_52 = ( void * ) V_2 -> V_7 ;
unsigned int V_36 = V_70 < V_52 -> V_31 ? V_70 : V_52 -> V_31 ;
int V_19 = - V_72 ;
switch ( V_69 ) {
case V_73 :
if ( V_52 -> V_74 )
V_19 = V_52 -> V_74 ( V_2 , V_71 , V_36 ) ;
break;
case V_75 :
if ( V_52 -> V_76 )
V_19 = V_52 -> V_76 ( V_2 , V_71 , V_36 ) ;
break;
}
return V_19 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_77 * V_29 =
(struct V_77 * ) V_2 -> V_7 ;
V_4 -> type = V_35 ;
V_4 -> V_36 = 1 ;
V_4 -> V_22 . integer . V_37 = V_29 -> V_37 ;
V_4 -> V_22 . integer . V_31 = V_29 -> V_31 ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_77 * V_29 =
(struct V_77 * ) V_2 -> V_7 ;
unsigned int V_78 = V_29 -> V_78 ;
unsigned int V_79 = V_29 -> V_79 ;
unsigned int V_80 = V_15 -> V_55 * V_81 ;
unsigned int V_82 = ( 1 << V_80 ) - 1 ;
unsigned int V_41 = V_29 -> V_41 ;
unsigned long V_21 = ( 1UL << V_29 -> V_83 ) - 1 ;
long V_37 = V_29 -> V_37 ;
long V_31 = V_29 -> V_31 ;
long V_16 = 0 ;
unsigned int V_84 ;
unsigned int V_85 ;
int V_19 ;
for ( V_85 = 0 ; V_85 < V_79 ; V_85 ++ ) {
V_19 = F_5 ( V_15 , V_78 + V_85 , & V_84 ) ;
if ( V_19 )
return V_19 ;
V_16 |= ( V_84 & V_82 ) << ( V_80 * ( V_79 - V_85 - 1 ) ) ;
}
V_16 &= V_21 ;
if ( V_37 < 0 && V_16 > V_31 )
V_16 |= ~ V_21 ;
if ( V_41 )
V_16 = V_31 - V_16 ;
V_13 -> V_22 . integer . V_22 [ 0 ] = V_16 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_77 * V_29 =
(struct V_77 * ) V_2 -> V_7 ;
unsigned int V_78 = V_29 -> V_78 ;
unsigned int V_79 = V_29 -> V_79 ;
unsigned int V_80 = V_15 -> V_55 * V_81 ;
unsigned int V_82 = ( 1 << V_80 ) - 1 ;
unsigned int V_41 = V_29 -> V_41 ;
unsigned long V_21 = ( 1UL << V_29 -> V_83 ) - 1 ;
long V_31 = V_29 -> V_31 ;
long V_16 = V_13 -> V_22 . integer . V_22 [ 0 ] ;
unsigned int V_85 , V_84 , V_86 ;
int V_42 ;
if ( V_41 )
V_16 = V_31 - V_16 ;
V_16 &= V_21 ;
for ( V_85 = 0 ; V_85 < V_79 ; V_85 ++ ) {
V_84 = ( V_16 >> ( V_80 * ( V_79 - V_85 - 1 ) ) ) & V_82 ;
V_86 = ( V_21 >> ( V_80 * ( V_79 - V_85 - 1 ) ) ) & V_82 ;
V_42 = F_9 ( V_15 , V_78 + V_85 ,
V_86 , V_84 ) ;
if ( V_42 < 0 )
return V_42 ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
unsigned int V_20 = V_29 -> V_20 ;
unsigned int V_25 = V_29 -> V_25 ;
unsigned int V_21 = 1 << V_25 ;
unsigned int V_41 = V_29 -> V_41 != 0 ;
unsigned int V_16 ;
int V_19 ;
V_19 = F_5 ( V_15 , V_20 , & V_16 ) ;
if ( V_19 )
return V_19 ;
V_16 &= V_21 ;
if ( V_25 != 0 && V_16 != 0 )
V_16 = V_16 >> V_25 ;
V_13 -> V_22 . V_23 . V_17 [ 0 ] = V_16 ^ V_41 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 =
(struct V_28 * ) V_2 -> V_7 ;
unsigned int V_20 = V_29 -> V_20 ;
unsigned int V_25 = V_29 -> V_25 ;
unsigned int V_21 = 1 << V_25 ;
unsigned int V_41 = V_29 -> V_41 != 0 ;
unsigned int V_87 = V_13 -> V_22 . V_23 . V_17 [ 0 ] != 0 ;
unsigned int V_88 = ( V_87 ^ V_41 ) ? V_21 : 0 ;
unsigned int V_44 = ( V_87 ^ V_41 ) ? 0 : V_21 ;
int V_42 ;
V_42 = F_9 ( V_15 , V_20 , V_21 , V_88 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_9 ( V_15 , V_20 , V_21 , V_44 ) ;
}
