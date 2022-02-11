struct V_1 *
F_1 ( int V_2 , int V_3 )
{
struct V_1 * V_4 ;
T_1 V_5 ;
F_2 ( & V_6 , V_5 ) ;
for ( V_4 = V_7 ; V_4 ; V_4 = V_4 -> V_8 )
if ( V_4 -> V_9 == V_2 && V_4 -> V_10 == V_3 )
break;
F_3 ( & V_6 , V_5 ) ;
return V_4 ;
}
static void
F_4 ( T_1 V_11 )
{
struct V_1 * V_4 ;
V_4 = (struct V_1 * ) V_11 ;
if ( V_4 -> V_5 & V_12 )
return;
V_4 -> V_13 . V_14 = V_15 + V_16 ;
F_5 ( & V_4 -> V_13 ) ;
}
void
F_6 ( struct V_1 * V_4 )
{
struct V_17 * * V_18 , * * V_19 ;
struct V_20 * V_21 , * V_22 ;
struct V_23 * V_23 ;
struct V_24 * V_24 ;
V_18 = V_4 -> V_25 ;
V_19 = V_18 + V_26 ;
for (; V_18 < V_19 && * V_18 ; V_18 ++ ) {
V_21 = ( * V_18 ) -> V_27 ;
V_22 = V_21 + ( * V_18 ) -> V_28 ;
for (; V_21 < V_22 ; V_21 -> V_29 = V_30 , V_21 -> V_23 = NULL , V_21 ++ ) {
if ( V_21 -> V_29 == V_30 || V_21 -> V_23 == NULL )
continue;
V_23 = V_21 -> V_23 ;
V_24 = V_23 -> V_24 ;
if ( -- V_23 -> V_31 == 0
&& V_23 != V_4 -> V_32 ) {
F_7 ( V_23 , V_4 -> V_33 ) ;
F_8 ( V_24 , - V_34 ) ;
}
}
( * V_18 ) -> V_35 = ( * V_18 ) -> V_28 ;
( * V_18 ) -> V_36 = 0 ;
}
V_23 = V_4 -> V_32 ;
if ( V_23 ) {
V_24 = V_23 -> V_24 ;
F_7 ( V_23 , V_4 -> V_33 ) ;
F_8 ( V_24 , - V_34 ) ;
}
V_4 -> V_32 = NULL ;
V_4 -> V_37 = NULL ;
while ( ! F_9 ( & V_4 -> V_38 ) ) {
V_23 = F_10 ( V_4 -> V_38 . V_8 , struct V_23 , V_39 ) ;
F_11 ( V_4 -> V_38 . V_8 ) ;
V_24 = V_23 -> V_24 ;
F_7 ( V_23 , V_4 -> V_33 ) ;
F_8 ( V_24 , - V_34 ) ;
}
if ( V_4 -> V_40 )
F_12 ( V_4 -> V_40 , 0 ) ;
V_4 -> V_5 &= ~ V_41 ;
}
static void
F_13 ( struct V_1 * V_4 )
{
struct V_17 * * V_18 , * * V_22 ;
F_14 ( & V_4 -> V_42 ) ;
if ( V_4 -> V_40 ) {
F_15 ( V_4 ) ;
F_16 ( V_4 -> V_40 ) ;
F_17 ( V_4 -> V_40 ) ;
}
V_18 = V_4 -> V_25 ;
V_22 = V_18 + V_26 ;
for (; V_18 < V_22 && * V_18 ; V_18 ++ )
F_18 ( V_4 , * V_18 ) ;
if ( V_4 -> V_33 )
F_19 ( V_4 -> V_33 ) ;
F_20 ( V_4 ) ;
F_21 ( V_4 -> V_43 ) ;
F_22 ( V_4 ) ;
}
int
F_23 ( const char T_2 * V_44 , T_3 V_45 )
{
T_1 V_5 ;
struct V_1 * V_4 , * * V_46 ;
struct V_1 * V_47 = NULL ;
char V_23 [ 16 ] ;
int V_48 = 0 ;
if ( V_45 >= 3 ) {
if ( V_45 > sizeof V_23 )
V_45 = sizeof V_23 ;
if ( F_24 ( V_23 , V_44 , V_45 ) )
return - V_49 ;
V_48 = ! strncmp ( V_23 , L_1 , 3 ) ;
}
F_2 ( & V_6 , V_5 ) ;
V_46 = & V_7 ;
while ( ( V_4 = * V_46 ) ) {
F_25 ( & V_4 -> V_50 ) ;
if ( ( ! V_48 && ( V_4 -> V_5 & V_41 ) )
|| ( V_4 -> V_5 & ( V_51 | V_52 ) )
|| V_4 -> V_53 ) {
F_26 ( & V_4 -> V_50 ) ;
V_46 = & V_4 -> V_8 ;
continue;
}
* V_46 = V_4 -> V_8 ;
F_6 ( V_4 ) ;
V_4 -> V_5 |= V_12 ;
F_26 ( & V_4 -> V_50 ) ;
V_4 -> V_8 = V_47 ;
V_47 = V_4 ;
}
F_3 ( & V_6 , V_5 ) ;
while ( ( V_4 = V_47 ) ) {
V_47 = V_4 -> V_8 ;
F_27 ( & V_4 -> V_13 ) ;
F_13 ( V_4 ) ;
}
return 0 ;
}
static void
F_28 ( struct V_54 * V_55 )
{
enum { V_56 = 100 , V_57 = 3 * 1000 };
int V_58 = V_57 / V_56 ;
if ( V_55 == NULL )
return;
while ( F_29 ( & F_30 ( V_55 ) -> V_59 ) != 1 && V_58 -- > 0 )
F_31 ( V_56 ) ;
if ( V_58 < 0 ) {
F_32 ( V_60
L_2 ,
V_55 -> V_61 ? V_55 -> V_61 -> V_62 : L_3 ,
L_4 ) ;
return;
}
F_30 ( V_55 ) -> V_63 = V_55 -> V_64 = 0 ;
F_33 ( V_55 , 0 ) ;
F_34 ( V_55 ) ;
}
static void
F_20 ( struct V_1 * V_4 )
{
struct V_54 * V_55 , * V_65 ;
F_35 (&d->skbpool, skb, tmp)
F_28 ( V_55 ) ;
F_36 ( & V_4 -> V_66 ) ;
}
struct V_1 *
F_37 ( T_1 V_67 )
{
struct V_1 * V_4 ;
T_1 V_5 ;
F_2 ( & V_6 , V_5 ) ;
for ( V_4 = V_7 ; V_4 ; V_4 = V_4 -> V_8 )
if ( V_4 -> V_67 == V_67 )
break;
if ( V_4 )
goto V_68;
V_4 = F_38 ( 1 , sizeof *V_4 , V_69 ) ;
if ( ! V_4 )
goto V_68;
F_39 ( & V_4 -> V_42 , V_70 ) ;
F_40 ( & V_4 -> V_50 ) ;
F_41 ( & V_4 -> V_71 ) ;
F_41 ( & V_4 -> V_66 ) ;
F_42 ( & V_4 -> V_13 ) ;
V_4 -> V_13 . V_72 = ( T_1 ) V_4 ;
V_4 -> V_13 . V_73 = F_4 ;
V_4 -> V_13 . V_14 = V_15 + V_16 ;
F_5 ( & V_4 -> V_13 ) ;
V_4 -> V_33 = NULL ;
V_4 -> V_74 = V_4 -> V_25 ;
F_43 ( & V_4 -> V_38 ) ;
V_4 -> V_67 = V_67 ;
V_4 -> V_9 = F_44 ( V_67 ) ;
V_4 -> V_10 = F_45 ( V_67 ) ;
V_4 -> V_75 = V_76 ;
V_4 -> V_8 = V_7 ;
V_7 = V_4 ;
V_68:
F_3 ( & V_6 , V_5 ) ;
return V_4 ;
}
static void
F_18 ( struct V_1 * V_4 , struct V_17 * V_18 )
{
struct V_20 * V_21 , * V_22 ;
V_21 = V_18 -> V_27 ;
V_22 = V_21 + V_18 -> V_28 ;
for (; V_21 < V_22 ; V_21 ++ )
F_28 ( V_21 -> V_55 ) ;
F_22 ( V_18 -> V_27 ) ;
F_22 ( V_18 ) ;
}
void
F_46 ( void )
{
struct V_1 * V_4 ;
T_1 V_5 ;
while ( ( V_4 = V_7 ) ) {
V_7 = V_4 -> V_8 ;
F_2 ( & V_4 -> V_50 , V_5 ) ;
F_6 ( V_4 ) ;
V_4 -> V_5 |= V_12 ;
F_3 ( & V_4 -> V_50 , V_5 ) ;
F_27 ( & V_4 -> V_13 ) ;
F_13 ( V_4 ) ;
}
}
int T_4
F_47 ( void )
{
return 0 ;
}
