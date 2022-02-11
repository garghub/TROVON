void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
T_1 V_10 ;
#ifdef F_2
F_3 ( V_11 L_1 ,
V_6 -> V_12 . V_13 . V_14 ) ;
#endif
if ( ( V_9 = F_4 ( V_6 -> V_12 . V_13 . V_14 , & V_8 ,
V_4 -> V_15 ) ) < 0 )
{
F_3 ( L_2 ) ;
return;
}
V_10 = V_16 ++ & 0x7fffU ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
V_4 -> V_19 = 0 ;
V_4 -> V_20 = V_10 ;
F_5 ( V_2 , V_21 , V_10 , V_8 , V_9 ) ;
}
void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_12 )
{
T_2 V_22 ;
struct V_7 * V_8 ;
int V_9 ;
T_1 V_10 ;
if ( ( V_9 = F_7 ( V_4 , & V_8 ) ) < 0 )
{
F_3 ( L_3 ) ;
return;
}
V_10 = V_16 ++ & 0x7fffU ;
V_4 -> V_20 = V_10 ;
F_5 ( V_2 , V_23 , V_10 , V_8 , V_9 ) ;
V_22 . V_24 = V_25 ;
V_22 . V_26 = V_2 -> V_27 ;
V_22 . V_28 = V_4 -> V_27 ;
V_2 -> V_29 -> V_30 ( & V_22 ) ;
if ( ( V_9 = F_8 ( V_4 , & V_8 , 1 ) ) < 0 ) {
F_3 ( L_4 ) ;
return;
}
V_10 = V_16 ++ & 0x7fffU ;
V_4 -> V_20 = V_10 ;
F_5 ( V_2 , V_31 , V_10 , V_8 , V_9 ) ;
}
void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_2 V_22 ;
unsigned short V_10 ;
struct V_7 * V_8 ;
int V_9 ;
V_22 . V_24 = V_32 ;
V_22 . V_26 = V_2 -> V_27 ;
V_22 . V_28 = V_4 -> V_27 ;
if ( V_6 -> V_12 . V_13 . V_33 == NULL ) {
F_3 ( V_11 L_5 ) ;
strcpy ( V_22 . V_34 . V_13 . V_35 , L_6 ) ;
}
else {
strcpy ( V_22 . V_34 . V_13 . V_35 , V_6 -> V_12 . V_13 . V_33 ) ;
}
if ( V_6 -> V_12 . V_13 . V_14 == NULL ) {
F_3 ( V_11 L_7 ) ;
strcpy ( V_22 . V_34 . V_13 . V_36 , L_6 ) ;
}
else {
strcpy ( V_22 . V_34 . V_13 . V_36 , V_6 -> V_12 . V_13 . V_14 ) ;
}
V_22 . V_34 . V_13 . V_37 = 7 ;
V_22 . V_34 . V_13 . V_38 = 0 ;
V_22 . V_34 . V_13 . V_39 = 0 ;
V_22 . V_34 . V_13 . V_40 = 0 ;
#ifdef F_2
F_3 ( V_11 L_8 , V_22 . V_41 ) ;
#endif
V_2 -> V_29 -> V_30 ( & V_22 ) ;
if ( ( V_9 = F_10 ( V_4 , & V_8 ) ) < 0 ) {
F_3 ( V_11 L_9 ) ;
return;
}
V_10 = V_16 ++ & 0x7fffU ;
V_4 -> V_20 = V_10 ;
F_5 ( V_2 , V_42 , V_10 , V_8 , V_9 ) ;
}
void F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_12 )
{
unsigned short V_10 ;
struct V_7 * V_8 ;
int V_9 ;
if ( ( V_9 = F_12 ( V_4 , & V_8 ) ) < 0 ) {
F_3 ( V_11 L_3 ) ;
return;
}
V_10 = V_16 ++ & 0x7fffU ;
V_4 -> V_20 = V_10 ;
F_3 ( V_11 L_10 ) ;
F_5 ( V_2 , V_43 , V_10 , V_8 , V_9 ) ;
}
void F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_12 )
{
unsigned short V_10 ;
struct V_7 * V_8 ;
int V_9 ;
if ( ( V_9 = F_8 ( V_4 , & V_8 , 0 ) ) < 0 )
{
F_3 ( L_4 ) ;
return;
}
V_10 = V_16 ++ & 0x7fffU ;
V_4 -> V_20 = V_10 ;
F_5 ( V_2 , V_31 , V_10 , V_8 , V_9 ) ;
}
void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_12 )
{
struct V_7 * V_8 ;
int V_9 ;
T_1 V_10 ;
T_2 V_22 ;
if ( ( V_9 = F_15 ( V_4 , & V_8 ) ) < 0 ) {
F_3 ( L_11 ) ;
return;
}
V_10 = V_16 ++ & 0x7fffU ;
V_4 -> V_20 = V_10 ;
F_5 ( V_2 , V_44 , V_10 , V_8 , V_9 ) ;
V_22 . V_24 = V_45 ;
V_22 . V_26 = V_2 -> V_27 ;
V_22 . V_28 = V_4 -> V_27 ;
V_2 -> V_29 -> V_30 ( & V_22 ) ;
}
void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_12 )
{
struct V_7 * V_8 ;
int V_9 ;
T_1 V_10 ;
if ( ( V_9 = F_17 ( V_4 -> V_17 , & V_8 , V_46 ) ) < 0 )
{
F_3 ( L_12 ) ;
return;
}
V_10 = V_16 ++ & 0x7fffU ;
V_4 -> V_20 = V_10 ;
F_5 ( V_2 , V_47 , V_10 , V_8 , V_9 ) ;
}
void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_12 )
{
T_2 V_22 ;
V_22 . V_24 = V_45 ;
V_22 . V_26 = V_2 -> V_27 ;
V_22 . V_28 = V_4 -> V_27 ;
V_2 -> V_29 -> V_30 ( & V_22 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_12 )
{
}
void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_12 )
{
struct V_7 * V_8 ;
int V_9 ;
T_1 V_10 ;
if ( ( V_9 = F_21 ( V_4 , & V_8 ) ) < 0 )
{
F_3 ( L_13 ) ;
return;
}
V_10 = V_16 ++ & 0x7fffU ;
V_4 -> V_20 = V_10 ;
F_5 ( V_2 , V_48 , V_10 , V_8 , V_9 ) ;
}
void F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_12 )
{
T_2 V_22 ;
V_22 . V_24 = V_49 ;
V_22 . V_26 = V_2 -> V_27 ;
V_22 . V_28 = V_4 -> V_27 ;
V_2 -> V_29 -> V_30 ( & V_22 ) ;
}
