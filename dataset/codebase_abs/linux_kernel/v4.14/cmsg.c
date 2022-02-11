static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
struct V_2 *
F_2 ( struct V_5 * V_6 , unsigned int V_7 ,
enum V_8 type )
{
struct V_1 * V_9 ;
struct V_2 * V_3 ;
V_7 += V_10 ;
V_3 = F_3 ( V_6 , V_7 , V_11 ) ;
if ( ! V_3 )
return NULL ;
V_9 = F_1 ( V_3 ) ;
V_9 -> V_12 = 0 ;
V_9 -> V_13 = V_14 ;
V_9 -> type = type ;
F_4 ( V_3 , V_7 ) ;
return V_3 ;
}
struct V_2 *
F_5 ( struct V_5 * V_6 , unsigned int V_15 )
{
struct V_16 * V_17 ;
struct V_2 * V_3 ;
unsigned int V_7 ;
V_7 = sizeof( * V_17 ) + V_15 * sizeof( V_17 -> V_18 [ 0 ] ) ;
V_3 = F_2 ( V_6 , V_7 , V_19 ) ;
if ( ! V_3 )
return NULL ;
V_17 = F_6 ( V_3 ) ;
memset ( V_17 -> V_20 , 0 , sizeof( V_17 -> V_20 ) ) ;
V_17 -> V_15 = V_15 ;
return V_3 ;
}
void
F_7 ( struct V_2 * V_3 , unsigned int V_21 ,
unsigned int V_22 , unsigned int V_23 ,
unsigned int V_24 )
{
struct V_16 * V_17 ;
V_17 = F_6 ( V_3 ) ;
V_17 -> V_18 [ V_21 ] . V_21 = V_21 ;
V_17 -> V_18 [ V_21 ] . V_25 = V_22 & V_26 ;
V_17 -> V_18 [ V_21 ] . V_23 = V_23 ;
V_17 -> V_18 [ V_21 ] . V_24 = V_24 ;
}
int F_8 ( struct V_27 * V_28 , bool V_29 )
{
struct F_8 * V_17 ;
struct V_2 * V_3 ;
V_3 = F_2 ( V_28 -> V_6 , sizeof( * V_17 ) ,
V_30 ) ;
if ( ! V_3 )
return - V_31 ;
V_17 = F_6 ( V_3 ) ;
V_17 -> V_32 = F_9 ( V_28 -> V_33 -> V_34 . V_35 . V_36 ) ;
V_17 -> V_20 = 0 ;
V_17 -> V_25 = V_29 ;
V_17 -> V_37 = F_10 ( V_28 -> V_38 -> V_37 ) ;
F_11 ( V_28 -> V_6 -> V_39 , V_3 ) ;
return 0 ;
}
static void
F_12 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct F_8 * V_17 ;
struct V_40 * V_38 ;
bool V_41 ;
V_17 = F_6 ( V_3 ) ;
V_41 = V_17 -> V_25 & V_42 ;
F_13 () ;
F_14 () ;
V_38 = F_15 ( V_6 , F_16 ( V_17 -> V_32 ) ) ;
F_17 () ;
if ( ! V_38 ) {
F_18 ( V_6 , L_1 ,
F_16 ( V_17 -> V_32 ) ) ;
F_19 () ;
return;
}
if ( V_41 ) {
T_1 V_37 = F_20 ( V_17 -> V_37 ) ;
F_21 ( V_38 ) ;
if ( V_37 )
F_22 ( V_38 , V_37 ) ;
} else {
F_23 ( V_38 ) ;
}
F_19 () ;
}
static void
F_24 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_1 * V_43 ;
enum V_8 type ;
V_43 = F_1 ( V_3 ) ;
if ( F_25 ( V_43 -> V_13 != V_14 ) ) {
F_18 ( V_6 , L_2 ,
V_43 -> V_13 ) ;
goto V_44;
}
type = V_43 -> type ;
switch ( type ) {
case V_30 :
F_12 ( V_6 , V_3 ) ;
break;
case V_45 :
F_26 ( V_6 , V_3 ) ;
break;
default:
F_18 ( V_6 , L_3 ,
type ) ;
goto V_44;
}
F_27 ( V_3 ) ;
return;
V_44:
F_28 ( V_3 ) ;
}
void F_29 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_2 * V_3 ;
V_49 = F_30 ( V_47 , struct V_48 , V_50 ) ;
while ( ( V_3 = F_31 ( & V_49 -> V_51 ) ) )
F_24 ( V_49 -> V_6 , V_3 ) ;
}
void F_32 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_48 * V_49 = V_6 -> V_49 ;
F_33 ( & V_49 -> V_51 , V_3 ) ;
F_34 ( & V_49 -> V_50 ) ;
}
