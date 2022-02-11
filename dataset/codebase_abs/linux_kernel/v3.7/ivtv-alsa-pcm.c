void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 ;
unsigned int V_10 ;
int V_11 = 0 ;
int V_12 ;
F_2 ( L_1 , V_2 ,
V_3 , V_4 ) ;
V_6 = V_2 -> V_13 ;
if ( V_6 == NULL ) {
F_2 ( L_2 ) ;
return;
}
V_8 = V_6 -> V_8 ;
if ( V_8 == NULL ) {
F_2 ( L_3 ) ;
return;
}
V_10 = V_8 -> V_14 >> 3 ;
if ( V_10 == 0 ) {
F_2 ( L_4 ) ;
return;
}
V_12 = V_4 / V_10 ;
if ( V_12 == 0 ) {
F_2 ( L_5 , V_15 ) ;
return;
}
if ( V_8 -> V_16 == NULL ) {
F_2 ( L_6 ) ;
return;
}
V_9 = V_2 -> V_17 ;
if ( V_9 + V_12 >= V_8 -> V_18 ) {
unsigned int V_19 =
V_8 -> V_18 - V_9 ;
memcpy ( V_8 -> V_16 + V_9 * V_10 , V_3 ,
V_19 * V_10 ) ;
memcpy ( V_8 -> V_16 , V_3 + V_19 * V_10 ,
V_12 * V_10 - V_19 * V_10 ) ;
} else {
memcpy ( V_8 -> V_16 + V_9 * V_10 , V_3 ,
V_12 * V_10 ) ;
}
F_3 ( V_6 ) ;
V_2 -> V_17 += V_12 ;
if ( V_2 -> V_17 >=
V_8 -> V_18 )
V_2 -> V_17 -=
V_8 -> V_18 ;
V_2 -> V_20 += V_12 ;
if ( V_2 -> V_20 >=
V_8 -> V_21 ) {
V_2 -> V_20 -=
V_8 -> V_21 ;
V_11 = 1 ;
}
F_4 ( V_6 ) ;
if ( V_11 )
F_5 ( V_6 ) ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 = F_8 ( V_23 ) ;
struct V_26 * V_27 ;
struct V_28 V_29 ;
int V_30 ;
F_9 ( V_2 ) ;
V_27 = & V_25 -> V_31 [ V_32 ] ;
F_10 ( & V_29 . V_33 , V_27 -> V_34 ) ;
V_29 . V_25 = V_25 ;
V_29 . type = V_27 -> type ;
if ( F_11 ( & V_29 , V_29 . type ) ) {
F_12 ( V_2 ) ;
return - V_35 ;
}
if ( F_13 ( V_36 , & V_27 -> V_37 ) ||
F_14 ( V_38 , & V_27 -> V_37 ) ) {
F_12 ( V_2 ) ;
return 0 ;
}
V_8 -> V_39 = V_40 ;
F_15 ( V_8 , V_41 ) ;
V_2 -> V_13 = V_6 ;
V_8 -> V_42 = V_25 ;
V_25 -> V_43 = F_1 ;
F_16 ( V_38 , & V_27 -> V_37 ) ;
V_30 = F_17 ( V_27 ) ;
F_12 ( V_2 ) ;
return V_30 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 = F_8 ( V_23 ) ;
struct V_26 * V_27 ;
F_9 ( V_2 ) ;
V_27 = & V_25 -> V_31 [ V_32 ] ;
F_19 ( V_27 , 0 ) ;
F_20 ( V_38 , & V_27 -> V_37 ) ;
F_21 ( V_27 ) ;
V_25 -> V_43 = NULL ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
unsigned int V_44 , void * V_45 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
int V_30 ;
F_9 ( V_2 ) ;
V_30 = F_23 ( V_6 , V_44 , V_45 ) ;
F_12 ( V_2 ) ;
return V_30 ;
}
static int F_24 ( struct V_5 * V_46 ,
T_2 V_47 )
{
struct V_7 * V_8 = V_46 -> V_8 ;
F_2 ( L_7 ) ;
if ( V_8 -> V_16 ) {
if ( V_8 -> V_48 > V_47 )
return 0 ;
F_25 ( V_8 -> V_16 ) ;
}
V_8 -> V_16 = F_26 ( V_47 ) ;
if ( ! V_8 -> V_16 )
return - V_49 ;
V_8 -> V_48 = V_47 ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_50 * V_51 )
{
F_2 ( L_8 , V_15 ) ;
return F_24 ( V_6 ,
F_28 ( V_51 ) ) ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned long V_52 ;
F_30 ( & V_2 -> V_53 , V_52 ) ;
if ( V_6 -> V_8 -> V_16 ) {
F_2 ( L_9 ) ;
F_25 ( V_6 -> V_8 -> V_16 ) ;
V_6 -> V_8 -> V_16 = NULL ;
}
F_31 ( & V_2 -> V_53 , V_52 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
V_2 -> V_17 = 0 ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static int F_33 ( struct V_5 * V_6 , int V_44 )
{
return 0 ;
}
static
T_3 F_34 ( struct V_5 * V_6 )
{
unsigned long V_52 ;
T_3 V_54 ;
struct V_1 * V_2 = F_7 ( V_6 ) ;
F_30 ( & V_2 -> V_53 , V_52 ) ;
V_54 = V_2 -> V_17 ;
F_31 ( & V_2 -> V_53 , V_52 ) ;
return V_54 ;
}
static struct V_55 * F_35 ( struct V_5 * V_46 ,
unsigned long V_56 )
{
void * V_57 = V_46 -> V_8 -> V_16 + V_56 ;
return F_36 ( V_57 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 = V_2 -> V_61 ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 = F_8 ( V_23 ) ;
int V_30 ;
V_30 = F_38 ( V_61 , L_10 ,
0 ,
0 ,
1 ,
& V_59 ) ;
if ( V_30 ) {
F_39 ( L_11 ,
V_15 , V_30 ) ;
goto V_62;
}
F_40 ( & V_2 -> V_53 ) ;
F_41 ( V_59 , V_63 ,
& V_64 ) ;
V_59 -> V_65 = 0 ;
V_59 -> V_42 = V_2 ;
F_42 ( V_59 -> V_66 , V_25 -> V_67 , sizeof( V_59 -> V_66 ) ) ;
return 0 ;
V_62:
return V_30 ;
}
