static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_3 = false ;
}
void F_2 ( struct V_4 * V_5 )
{
unsigned int V_6 ;
V_5 -> V_7 . V_8 = NULL ;
V_5 -> V_7 . V_9 = NULL ;
V_5 -> V_7 . V_10 = NULL ;
V_5 -> V_7 . V_11 = NULL ;
for ( V_6 = 0 ; V_6 < F_3 ( V_5 -> V_7 . V_12 ) ; ++ V_6 )
V_5 -> V_7 . V_12 [ V_6 ] . V_3 = false ;
}
void F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_13 ;
unsigned int V_6 ;
F_5 ( & V_5 -> V_14 , V_13 ) ;
for ( V_6 = 0 ; V_6 < F_3 ( V_5 -> V_7 . V_12 ) ; ++ V_6 ) {
if ( ! V_5 -> V_7 . V_12 [ V_6 ] . V_3 ) {
V_2 = & V_5 -> V_7 . V_12 [ V_6 ] ;
break;
}
}
if ( ! V_2 ) {
V_2 = V_5 -> V_7 . V_10 ;
V_5 -> V_7 . V_10 = NULL ;
}
F_6 ( & V_5 -> V_14 , V_13 ) ;
V_5 -> V_7 . V_11 = V_2 ;
V_2 -> V_3 = true ;
V_2 -> V_15 = 0 ;
}
void F_7 ( struct V_16 * V_17 , T_1 V_18 , T_1 V_19 )
{
struct V_20 * V_21 = F_8 ( & V_17 -> V_22 . V_23 ) ;
struct V_4 * V_5 = V_21 -> V_5 ;
struct V_1 * V_2 = V_5 -> V_7 . V_11 ;
V_2 -> V_24 [ V_2 -> V_15 ] . V_25 = V_18 ;
V_2 -> V_24 [ V_2 -> V_15 ] . V_19 = V_19 ;
V_2 -> V_15 ++ ;
}
void F_9 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
struct V_1 * V_2 ;
unsigned long V_13 ;
bool V_28 ;
V_2 = V_5 -> V_7 . V_11 ;
V_5 -> V_7 . V_11 = NULL ;
F_5 ( & V_5 -> V_14 , V_13 ) ;
V_28 = ! ! ( F_10 ( V_27 , V_29 ) & V_30 ) ;
if ( V_28 ) {
F_1 ( V_5 -> V_7 . V_10 ) ;
V_5 -> V_7 . V_10 = V_2 ;
goto V_31;
}
F_11 ( V_27 , F_12 ( 0 ) , V_2 -> V_32 ) ;
F_11 ( V_27 , V_29 , V_30 |
( V_2 -> V_15 * 8 ) ) ;
F_1 ( V_5 -> V_7 . V_9 ) ;
V_5 -> V_7 . V_9 = V_2 ;
V_31:
F_6 ( & V_5 -> V_14 , V_13 ) ;
}
void F_13 ( struct V_4 * V_5 )
{
F_14 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 . V_8 ) {
F_1 ( V_5 -> V_7 . V_8 ) ;
V_5 -> V_7 . V_8 = NULL ;
}
F_15 ( & V_5 -> V_14 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_27 ;
F_14 ( & V_5 -> V_14 ) ;
if ( F_10 ( V_27 , V_29 ) & V_30 )
goto V_31;
if ( V_5 -> V_7 . V_9 ) {
F_17 ( V_5 -> V_7 . V_8 ) ;
V_5 -> V_7 . V_8 = V_5 -> V_7 . V_9 ;
V_5 -> V_7 . V_9 = NULL ;
}
if ( V_5 -> V_7 . V_10 ) {
struct V_1 * V_2 = V_5 -> V_7 . V_10 ;
F_11 ( V_27 , F_12 ( 0 ) , V_2 -> V_32 ) ;
F_11 ( V_27 , V_29 , V_30 |
( V_2 -> V_15 * 8 ) ) ;
V_5 -> V_7 . V_9 = V_2 ;
V_5 -> V_7 . V_10 = NULL ;
}
V_31:
F_15 ( & V_5 -> V_14 ) ;
}
void F_18 ( struct V_26 * V_27 )
{
T_1 V_33 = ( 256 << V_34 )
| V_35 | V_36 | V_37
| V_38 ;
if ( V_27 -> V_39 )
V_33 |= V_40 | V_41 ;
F_11 ( V_27 , V_42 , V_33 ) ;
F_11 ( V_27 , V_43 , V_44 ) ;
}
struct V_4 * F_19 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
unsigned int V_6 ;
V_5 = F_20 ( sizeof( * V_5 ) , V_45 ) ;
if ( ! V_5 )
return NULL ;
F_21 ( & V_5 -> V_14 ) ;
V_5 -> V_27 = V_27 ;
V_5 -> V_46 = V_47 * F_3 ( V_5 -> V_7 . V_12 ) ;
V_5 -> V_48 = F_22 ( V_27 -> V_49 , V_5 -> V_46 , & V_5 -> V_32 ,
V_45 ) ;
if ( ! V_5 -> V_48 ) {
F_23 ( V_5 ) ;
return NULL ;
}
for ( V_6 = 0 ; V_6 < F_3 ( V_5 -> V_7 . V_12 ) ; ++ V_6 ) {
struct V_1 * V_2 = & V_5 -> V_7 . V_12 [ V_6 ] ;
V_2 -> V_46 = V_47 ;
V_2 -> V_15 = 0 ;
V_2 -> V_3 = false ;
V_2 -> V_32 = V_5 -> V_32 + V_47 * V_6 ;
V_2 -> V_24 = V_5 -> V_48 + V_47 * V_6 ;
}
return V_5 ;
}
void F_24 ( struct V_4 * V_5 )
{
F_25 ( V_5 -> V_27 -> V_49 , V_5 -> V_46 , V_5 -> V_48 , V_5 -> V_32 ) ;
F_23 ( V_5 ) ;
}
