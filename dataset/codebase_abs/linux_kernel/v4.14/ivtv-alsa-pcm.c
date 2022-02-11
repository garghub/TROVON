static void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
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
if ( F_10 ( V_25 ) ) {
F_11 ( V_2 ) ;
return - V_31 ;
}
V_27 = & V_25 -> V_32 [ V_33 ] ;
F_12 ( & V_29 . V_34 , & V_27 -> V_35 ) ;
V_29 . V_25 = V_25 ;
V_29 . type = V_27 -> type ;
if ( F_13 ( & V_29 , V_29 . type ) ) {
F_14 ( & V_29 . V_34 ) ;
F_11 ( V_2 ) ;
return - V_36 ;
}
if ( F_15 ( V_37 , & V_27 -> V_38 ) ||
F_16 ( V_39 , & V_27 -> V_38 ) ) {
F_11 ( V_2 ) ;
return 0 ;
}
V_8 -> V_40 = V_41 ;
F_17 ( V_8 , V_42 ) ;
V_2 -> V_13 = V_6 ;
V_8 -> V_43 = V_25 ;
V_25 -> V_44 = F_1 ;
F_18 ( V_39 , & V_27 -> V_38 ) ;
V_30 = F_19 ( V_27 ) ;
F_11 ( V_2 ) ;
return V_30 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 = F_8 ( V_23 ) ;
struct V_26 * V_27 ;
F_9 ( V_2 ) ;
V_27 = & V_25 -> V_32 [ V_33 ] ;
F_21 ( V_27 , 0 ) ;
F_22 ( V_39 , & V_27 -> V_38 ) ;
F_23 ( V_27 ) ;
V_25 -> V_44 = NULL ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 ,
unsigned int V_45 , void * V_46 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
int V_30 ;
F_9 ( V_2 ) ;
V_30 = F_25 ( V_6 , V_45 , V_46 ) ;
F_11 ( V_2 ) ;
return V_30 ;
}
static int F_26 ( struct V_5 * V_47 ,
T_2 V_48 )
{
struct V_7 * V_8 = V_47 -> V_8 ;
F_2 ( L_7 ) ;
if ( V_8 -> V_16 ) {
if ( V_8 -> V_49 > V_48 )
return 0 ;
F_27 ( V_8 -> V_16 ) ;
}
V_8 -> V_16 = F_28 ( V_48 ) ;
if ( ! V_8 -> V_16 )
return - V_50 ;
V_8 -> V_49 = V_48 ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 ,
struct V_51 * V_52 )
{
F_2 ( L_8 , V_15 ) ;
return F_26 ( V_6 ,
F_30 ( V_52 ) ) ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned long V_53 ;
unsigned char * V_16 = NULL ;
F_32 ( & V_2 -> V_54 , V_53 ) ;
if ( V_6 -> V_8 -> V_16 ) {
F_2 ( L_9 ) ;
V_16 = V_6 -> V_8 -> V_16 ;
V_6 -> V_8 -> V_16 = NULL ;
}
F_33 ( & V_2 -> V_54 , V_53 ) ;
F_27 ( V_16 ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
V_2 -> V_17 = 0 ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 , int V_45 )
{
return 0 ;
}
static
T_3 F_36 ( struct V_5 * V_6 )
{
unsigned long V_53 ;
T_3 V_55 ;
struct V_1 * V_2 = F_7 ( V_6 ) ;
F_32 ( & V_2 -> V_54 , V_53 ) ;
V_55 = V_2 -> V_17 ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
return V_55 ;
}
static struct V_56 * F_37 ( struct V_5 * V_47 ,
unsigned long V_57 )
{
void * V_58 = V_47 -> V_8 -> V_16 + V_57 ;
return F_38 ( V_58 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 = F_8 ( V_23 ) ;
int V_30 ;
V_30 = F_40 ( V_62 , L_10 ,
0 ,
0 ,
1 ,
& V_60 ) ;
if ( V_30 ) {
F_41 ( L_11 ,
V_15 , V_30 ) ;
goto V_63;
}
F_42 ( & V_2 -> V_54 ) ;
F_43 ( V_60 , V_64 ,
& V_65 ) ;
V_60 -> V_66 = 0 ;
V_60 -> V_43 = V_2 ;
F_44 ( V_60 -> V_67 , V_25 -> V_68 , sizeof( V_60 -> V_67 ) ) ;
return 0 ;
V_63:
return V_30 ;
}
