static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , ! V_2 -> V_4 ) ;
if ( V_2 -> V_5 == V_6 )
F_3 ( V_2 -> V_3 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_2 -> V_9 = V_2 -> V_4 ;
F_6 ( V_2 -> V_3 , V_2 -> V_9 ) ;
V_2 -> V_10 = V_11 ;
F_7 ( & V_2 -> V_12 , V_2 -> V_10 + V_2 -> V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
F_7 ( & V_2 -> V_12 , 0 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
V_2 -> V_10 = V_11 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 , unsigned int V_14 )
{
V_8 -> V_15 = V_14 ;
return F_9 ( V_8 ) ;
}
static void F_11 ( unsigned long V_16 )
{
struct V_7 * V_8 = (struct V_7 * ) V_16 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
if ( F_12 ( V_11 , V_2 -> V_10 +
F_13 ( V_8 -> V_15 * 1000 ) ) ) {
F_14 ( V_8 -> V_17 , L_1 ) ;
return;
}
F_7 ( & V_2 -> V_12 , V_11 + V_2 -> V_13 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_2 -> V_9 = ! V_2 -> V_9 ;
F_2 ( V_2 -> V_3 , V_2 -> V_9 ) ;
break;
case V_18 :
F_2 ( V_2 -> V_3 , ! V_2 -> V_4 ) ;
F_15 ( 1 ) ;
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
break;
}
}
static int F_16 ( struct V_19 * V_20 , unsigned long V_21 ,
void * V_22 )
{
struct V_1 * V_2 = F_17 ( V_20 , struct V_1 ,
V_23 ) ;
F_7 ( & V_2 -> V_12 , 0 ) ;
switch ( V_21 ) {
case V_24 :
case V_25 :
F_1 ( V_2 ) ;
break;
default:
break;
}
return V_26 ;
}
static int F_18 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
enum V_29 V_30 ;
unsigned int V_13 ;
unsigned long V_31 = 0 ;
const char * V_32 ;
int V_33 ;
V_2 = F_19 ( & V_28 -> V_17 , sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_3 = F_20 ( V_28 -> V_17 . V_36 , 0 , & V_30 ) ;
if ( ! F_21 ( V_2 -> V_3 ) )
return V_2 -> V_3 ;
V_2 -> V_4 = V_30 & V_37 ;
V_33 = F_22 ( V_28 -> V_17 . V_36 , L_2 , & V_32 ) ;
if ( V_33 )
return V_33 ;
if ( ! strncmp ( V_32 , L_3 , 6 ) ) {
V_2 -> V_5 = V_6 ;
V_31 = V_38 ;
} else if ( ! strncmp ( V_32 , L_4 , 5 ) ) {
V_2 -> V_5 = V_18 ;
V_31 = V_2 -> V_4 ? V_39 : V_40 ;
} else {
return - V_41 ;
}
V_33 = F_23 ( & V_28 -> V_17 , V_2 -> V_3 , V_31 ,
F_24 ( & V_28 -> V_17 ) ) ;
if ( V_33 )
return V_33 ;
V_33 = F_25 ( V_28 -> V_17 . V_36 ,
L_5 , & V_13 ) ;
if ( V_33 )
return V_33 ;
if ( V_13 < 2 || V_13 > 65535 )
return - V_41 ;
V_2 -> V_13 = F_13 ( V_13 / 2 ) ;
F_26 ( & V_2 -> V_8 , V_2 ) ;
V_2 -> V_8 . V_42 = & V_43 ;
V_2 -> V_8 . V_44 = & V_45 ;
V_2 -> V_8 . V_46 = V_47 ;
V_2 -> V_8 . V_48 = V_49 ;
if ( F_27 ( & V_2 -> V_8 , 0 , & V_28 -> V_17 ) < 0 )
V_2 -> V_8 . V_15 = V_50 ;
F_28 ( & V_2 -> V_12 , F_11 , ( unsigned long ) & V_2 -> V_8 ) ;
V_33 = F_29 ( & V_2 -> V_8 ) ;
if ( V_33 )
return V_33 ;
V_2 -> V_23 . V_51 = F_16 ;
V_33 = F_30 ( & V_2 -> V_23 ) ;
if ( V_33 )
F_31 ( & V_2 -> V_8 ) ;
return V_33 ;
}
static int F_32 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_33 ( V_28 ) ;
F_34 ( & V_2 -> V_12 ) ;
F_35 ( & V_2 -> V_23 ) ;
F_31 ( & V_2 -> V_8 ) ;
return 0 ;
}
