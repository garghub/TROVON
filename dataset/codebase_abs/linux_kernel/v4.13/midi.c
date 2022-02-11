void F_1 ( struct V_1 * V_2 , unsigned char * V_3 ,
int V_4 )
{
if ( V_2 -> V_5 -> V_6 )
F_2 ( V_2 -> V_5 -> V_6 ,
V_3 , V_4 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_4 ( V_8 ) -> V_2 ;
struct V_9 * V_5 = V_2 -> V_5 ;
struct V_10 * V_11 = & V_5 -> V_12 ;
unsigned char V_13 [ V_14 ] ;
int V_15 , V_16 ;
for (; ; ) {
V_15 = F_5 ( F_6 ( V_11 ) , V_2 -> V_17 ) ;
V_16 = F_7 ( V_8 , V_13 , V_15 ) ;
if ( V_16 == 0 )
break;
F_8 ( V_11 , V_13 , V_16 ) ;
F_9 ( V_8 , V_16 ) ;
}
for (; ; ) {
V_16 = F_10 ( V_11 , V_13 ,
V_14 ) ;
if ( V_16 == 0 )
break;
F_11 ( V_2 , V_13 , V_16 ) ;
}
}
static void F_12 ( struct V_18 * V_18 )
{
unsigned long V_19 ;
int V_20 ;
int V_21 ;
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_22 ;
V_20 = V_18 -> V_20 ;
F_13 ( V_18 -> V_23 ) ;
F_14 ( V_18 ) ;
if ( V_20 == - V_24 )
return;
F_15 ( & V_2 -> V_5 -> V_25 , V_19 ) ;
V_21 = -- V_2 -> V_5 -> V_26 ;
if ( V_21 == 0 ) {
F_3 ( V_2 -> V_5 -> V_27 ) ;
V_21 = V_2 -> V_5 -> V_26 ;
}
if ( V_21 == 0 )
F_16 ( & V_2 -> V_5 -> V_28 ) ;
F_17 ( & V_2 -> V_5 -> V_25 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned char * V_3 ,
int V_4 )
{
struct V_18 * V_18 ;
int V_29 ;
unsigned char * V_23 ;
V_18 = F_18 ( 0 , V_30 ) ;
if ( V_18 == NULL )
return - V_31 ;
V_23 = F_19 ( V_3 , V_4 , V_30 ) ;
if ( V_23 == NULL ) {
F_14 ( V_18 ) ;
return - V_31 ;
}
F_20 ( V_18 , V_2 -> V_32 ,
F_21 ( V_2 -> V_32 ,
V_2 -> V_33 -> V_34 ) ,
V_23 , V_4 , F_12 , V_2 ,
V_2 -> V_35 ) ;
V_18 -> V_36 = 0 ;
V_29 = F_22 ( V_18 , V_30 ) ;
if ( V_29 < 0 ) {
F_23 ( V_2 -> V_37 , L_1 ) ;
F_14 ( V_18 ) ;
return V_29 ;
}
++ V_2 -> V_5 -> V_26 ;
return 0 ;
}
static int F_24 ( struct V_7 * V_8 )
{
return 0 ;
}
static int F_25 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_26 ( struct V_7 * V_8 ,
int V_38 )
{
unsigned long V_19 ;
struct V_1 * V_2 =
F_4 ( V_8 ) -> V_2 ;
V_2 -> V_5 -> V_27 = V_8 ;
F_15 ( & V_2 -> V_5 -> V_25 , V_19 ) ;
if ( V_2 -> V_5 -> V_26 == 0 )
F_3 ( V_8 ) ;
F_17 ( & V_2 -> V_5 -> V_25 , V_19 ) ;
}
static void F_27 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_4 ( V_8 ) -> V_2 ;
struct V_9 * V_39 = V_2 -> V_5 ;
F_28 ( V_39 -> V_28 ,
V_39 -> V_26 == 0 ) ;
}
static int F_29 ( struct V_7 * V_8 )
{
return 0 ;
}
static int F_30 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_31 ( struct V_7 * V_8 ,
int V_38 )
{
struct V_1 * V_2 =
F_4 ( V_8 ) -> V_2 ;
if ( V_38 )
V_2 -> V_5 -> V_6 = V_8 ;
else
V_2 -> V_5 -> V_6 = NULL ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_40 * * V_41 )
{
struct V_40 * V_42 ;
int V_43 ;
V_43 = F_33 ( V_2 -> V_44 , L_2 , 0 , 1 , 1 , V_41 ) ;
if ( V_43 < 0 )
return V_43 ;
V_42 = * V_41 ;
strcpy ( V_42 -> V_45 , V_2 -> V_33 -> V_45 ) ;
strcpy ( V_42 -> V_46 , V_2 -> V_33 -> V_46 ) ;
V_42 -> V_47 =
V_48 |
V_49 | V_50 ;
F_34 ( V_42 , V_51 ,
& V_52 ) ;
F_34 ( V_42 , V_53 ,
& V_54 ) ;
return 0 ;
}
static void F_35 ( struct V_40 * V_42 )
{
struct V_9 * V_5 = V_42 -> V_55 ;
F_36 ( & V_5 -> V_56 ) ;
F_36 ( & V_5 -> V_12 ) ;
F_13 ( V_5 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_43 ;
struct V_40 * V_42 ;
struct V_9 * V_5 ;
if ( ! ( V_2 -> V_33 -> V_57 & V_58 ) ) {
return 0 ;
}
V_43 = F_32 ( V_2 , & V_42 ) ;
if ( V_43 < 0 )
return V_43 ;
V_5 = F_38 ( sizeof( struct V_9 ) , V_59 ) ;
if ( ! V_5 )
return - V_31 ;
V_42 -> V_55 = V_5 ;
V_42 -> V_60 = F_35 ;
F_39 ( & V_5 -> V_28 ) ;
F_40 ( & V_5 -> V_25 ) ;
V_5 -> V_2 = V_2 ;
V_43 = F_41 ( & V_5 -> V_56 , V_61 , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_41 ( & V_5 -> V_12 , V_61 , 1 ) ;
if ( V_43 < 0 )
return V_43 ;
V_2 -> V_5 = V_5 ;
return 0 ;
}
