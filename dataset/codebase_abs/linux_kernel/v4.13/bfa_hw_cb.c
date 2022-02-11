void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
void T_1 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_8 = F_3 ( & V_2 -> V_7 ) ;
if ( V_8 == 0 ) {
V_4 -> V_9 = ( V_6 + V_10 ) ;
V_4 -> V_11 = ( V_6 + V_12 ) ;
} else {
V_4 -> V_9 = ( V_6 + V_13 ) ;
V_4 -> V_11 = ( V_6 + V_14 ) ;
}
}
static void
F_4 ( struct V_1 * V_2 , int V_15 )
{
F_5 ( V_16 << F_6 ( F_3 ( & V_2 -> V_7 ) , V_15 ) ,
V_2 -> V_5 . V_4 . V_9 ) ;
}
static void
F_7 ( struct V_1 * V_2 , int V_17 , T_2 V_18 )
{
F_5 ( V_19 << F_8 ( F_3 ( & V_2 -> V_7 ) , V_17 ) ,
V_2 -> V_5 . V_4 . V_9 ) ;
if ( F_9 ( V_2 , V_17 ) == V_18 )
return;
F_9 ( V_2 , V_17 ) = V_18 ;
F_5 ( V_18 , V_2 -> V_5 . V_4 . V_20 [ V_17 ] ) ;
F_10 () ;
}
void
F_11 ( struct V_1 * V_2 , int V_17 , T_2 V_18 )
{
if ( F_9 ( V_2 , V_17 ) == V_18 )
return;
F_9 ( V_2 , V_17 ) = V_18 ;
F_5 ( V_18 , V_2 -> V_5 . V_4 . V_20 [ V_17 ] ) ;
F_10 () ;
}
void
F_12 ( struct V_1 * V_2 , T_2 * V_21 ,
T_2 * V_22 , T_2 * V_23 )
{
#define F_13 13
if ( F_3 ( & V_2 -> V_7 ) == 0 ) {
* V_21 = ( V_16 | V_24 |
V_25 | V_26 |
V_19 | V_27 |
V_28 | V_29 |
V_30 ) ;
* V_23 = V_30 ;
} else {
* V_21 = ( V_31 | V_32 |
V_33 | V_34 |
V_35 | V_36 |
V_37 | V_38 |
V_39 ) ;
* V_23 = V_39 ;
}
* V_21 |= ( V_40 | V_41 |
V_42 | V_43 ) ;
* V_22 = F_13 ;
}
static void
F_14 ( struct V_1 * V_2 , int V_44 )
{
}
void
F_15 ( struct V_1 * V_2 , int V_45 )
{
F_16 ( ( V_45 != 1 ) && ( V_45 != F_13 ) ) ;
V_2 -> V_46 . V_45 = V_45 ;
F_17 ( V_2 ) ;
}
void
F_18 ( struct V_1 * V_2 )
{
int V_47 ;
if ( V_2 -> V_46 . V_45 == 0 )
return;
if ( V_2 -> V_46 . V_45 == 1 ) {
for ( V_47 = V_48 ; V_47 < V_49 ; V_47 ++ )
V_2 -> V_46 . V_50 [ V_47 ] = V_51 ;
return;
}
for ( V_47 = V_52 + 1 ; V_47 < V_49 ; V_47 ++ )
V_2 -> V_46 . V_50 [ V_47 ] = V_53 ;
}
void
F_19 ( struct V_1 * V_2 )
{
int V_47 ;
if ( V_2 -> V_46 . V_45 == 0 )
return;
if ( V_2 -> V_46 . V_45 == 1 ) {
for ( V_47 = V_48 ; V_47 <= V_52 ; V_47 ++ )
V_2 -> V_46 . V_50 [ V_47 ] = V_51 ;
return;
}
for ( V_47 = V_48 ; V_47 <= V_54 ; V_47 ++ )
V_2 -> V_46 . V_50 [ V_47 ] = V_55 ;
for ( V_47 = V_56 ; V_47 <= V_52 ; V_47 ++ )
V_2 -> V_46 . V_50 [ V_47 ] = V_57 ;
}
void
F_17 ( struct V_1 * V_2 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_49 ; V_47 ++ )
V_2 -> V_46 . V_50 [ V_47 ] = F_14 ;
}
void
F_20 ( struct V_1 * V_2 , T_3 V_46 )
{
if ( V_46 ) {
V_2 -> V_5 . V_58 . V_59 = F_4 ;
V_2 -> V_5 . V_58 . V_60 = F_7 ;
} else {
V_2 -> V_5 . V_58 . V_59 = NULL ;
V_2 -> V_5 . V_58 . V_60 = F_11 ;
}
}
void
F_21 ( struct V_1 * V_2 , T_2 * V_61 , T_2 * V_62 )
{
* V_61 = V_56 ;
* V_62 = V_52 ;
}
