static struct V_1 * F_1 ( T_1 V_2 ,
unsigned long V_3 )
{
struct V_1 * V_4 ;
F_2 (map, &acpi_iomaps, list) {
if ( V_4 -> V_2 + V_4 -> V_3 >= V_2 + V_3 &&
V_4 -> V_2 <= V_2 )
return V_4 ;
}
return NULL ;
}
static void T_2 * F_3 ( T_1 V_2 ,
unsigned long V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_3 / 8 ) ;
if ( V_4 )
return V_4 -> V_5 + ( V_2 - V_4 -> V_2 ) ;
else
return NULL ;
}
static void T_2 * F_4 ( T_1 V_2 ,
unsigned long V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 ) {
F_5 ( & V_4 -> V_6 ) ;
return V_4 -> V_5 + ( V_2 - V_4 -> V_2 ) ;
} else
return NULL ;
}
static void T_2 * F_6 ( T_1 V_2 ,
unsigned long V_3 )
{
void T_2 * V_5 ;
struct V_1 * V_4 ;
unsigned long V_7 , V_8 ;
T_1 V_9 ;
F_7 ( & V_10 , V_8 ) ;
V_5 = F_4 ( V_2 , V_3 ) ;
F_8 ( & V_10 , V_8 ) ;
if ( V_5 )
return V_5 ;
V_9 = V_2 & V_11 ;
V_7 = ( ( V_2 + V_3 + V_12 - 1 ) & V_11 ) - V_9 ;
V_5 = F_9 ( V_9 , V_7 ) ;
if ( ! V_5 )
return NULL ;
V_4 = F_10 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 )
goto V_14;
F_11 ( & V_4 -> V_15 ) ;
V_4 -> V_2 = V_9 ;
V_4 -> V_3 = V_7 ;
V_4 -> V_5 = V_5 ;
F_12 ( & V_4 -> V_6 ) ;
F_7 ( & V_10 , V_8 ) ;
V_5 = F_4 ( V_2 , V_3 ) ;
if ( V_5 ) {
F_8 ( & V_10 , V_8 ) ;
F_13 ( V_4 -> V_5 ) ;
F_14 ( V_4 ) ;
return V_5 ;
}
F_15 ( & V_4 -> V_15 , & V_16 ) ;
F_8 ( & V_10 , V_8 ) ;
return V_4 -> V_5 + ( V_2 - V_4 -> V_2 ) ;
V_14:
F_13 ( V_5 ) ;
return NULL ;
}
static void F_16 ( struct V_17 * V_6 )
{
struct V_1 * V_4 ;
V_4 = F_17 ( V_6 , struct V_1 , V_6 ) ;
F_18 ( & V_4 -> V_15 ) ;
}
static void F_19 ( T_1 V_2 , unsigned long V_3 )
{
struct V_1 * V_4 ;
unsigned long V_8 ;
int V_18 ;
F_7 ( & V_10 , V_8 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
F_20 ( ! V_4 ) ;
V_18 = F_21 ( & V_4 -> V_6 , F_16 ) ;
F_8 ( & V_10 , V_8 ) ;
if ( ! V_18 )
return;
F_22 () ;
F_13 ( V_4 -> V_5 ) ;
F_14 ( V_4 ) ;
}
static int F_23 ( struct V_19 * V_20 ,
T_3 * V_2 , int V_21 )
{
T_4 V_22 , V_23 ;
V_22 = V_20 -> V_24 ;
V_23 = V_20 -> V_23 ;
memcpy ( V_2 , & V_20 -> V_25 , sizeof( * V_2 ) ) ;
if ( ! * V_2 ) {
if ( ! V_21 )
F_24 (FW_BUG ACPI_PFX
L_1 ,
*paddr, width, space_id) ;
return - V_26 ;
}
if ( ( V_22 != 8 ) && ( V_22 != 16 ) && ( V_22 != 32 ) && ( V_22 != 64 ) ) {
if ( ! V_21 )
F_24 (FW_BUG ACPI_PFX
L_2 ,
*paddr, width, space_id) ;
return - V_26 ;
}
if ( V_23 != V_27 &&
V_23 != V_28 ) {
if ( ! V_21 )
F_24 (FW_BUG ACPI_PFX
L_3 ,
*paddr, width, space_id) ;
return - V_26 ;
}
return 0 ;
}
int F_25 ( struct V_19 * V_20 )
{
T_3 V_2 ;
void T_2 * V_5 ;
int V_29 ;
if ( V_20 -> V_23 != V_27 )
return 0 ;
V_29 = F_23 ( V_20 , & V_2 , 0 ) ;
if ( V_29 )
return V_29 ;
V_5 = F_6 ( V_2 , V_20 -> V_24 / 8 ) ;
if ( ! V_5 )
return - V_30 ;
return 0 ;
}
int F_26 ( struct V_19 * V_20 )
{
T_3 V_2 ;
int V_29 ;
if ( V_20 -> V_23 != V_27 )
return 0 ;
V_29 = F_23 ( V_20 , & V_2 , 0 ) ;
if ( V_29 )
return V_29 ;
F_19 ( V_2 , V_20 -> V_24 / 8 ) ;
return 0 ;
}
static int F_27 ( T_3 V_2 , T_3 * V_31 , T_4 V_22 )
{
void T_2 * V_32 ;
F_28 () ;
V_32 = F_3 ( V_2 , V_22 ) ;
switch ( V_22 ) {
case 8 :
* V_31 = F_29 ( V_32 ) ;
break;
case 16 :
* V_31 = F_30 ( V_32 ) ;
break;
case 32 :
* V_31 = F_31 ( V_32 ) ;
break;
#ifdef F_32
case 64 :
* V_31 = F_32 ( V_32 ) ;
break;
#endif
default:
return - V_26 ;
}
F_33 () ;
return 0 ;
}
static int F_34 ( T_3 V_2 , T_3 V_31 , T_4 V_22 )
{
void T_2 * V_32 ;
F_28 () ;
V_32 = F_3 ( V_2 , V_22 ) ;
switch ( V_22 ) {
case 8 :
F_35 ( V_31 , V_32 ) ;
break;
case 16 :
F_36 ( V_31 , V_32 ) ;
break;
case 32 :
F_37 ( V_31 , V_32 ) ;
break;
#ifdef F_38
case 64 :
F_38 ( V_31 , V_32 ) ;
break;
#endif
default:
return - V_26 ;
}
F_33 () ;
return 0 ;
}
int F_39 ( T_3 * V_31 , struct V_19 * V_20 )
{
T_3 V_2 ;
int V_29 ;
V_29 = F_23 ( V_20 , & V_2 , 1 ) ;
if ( V_29 )
return V_29 ;
* V_31 = 0 ;
switch ( V_20 -> V_23 ) {
case V_27 :
return F_27 ( V_2 , V_31 , V_20 -> V_24 ) ;
case V_28 :
return F_40 ( V_2 , ( T_4 * ) V_31 , V_20 -> V_24 ) ;
default:
return - V_26 ;
}
}
int F_41 ( T_3 V_31 , struct V_19 * V_20 )
{
T_3 V_2 ;
int V_29 ;
V_29 = F_23 ( V_20 , & V_2 , 1 ) ;
if ( V_29 )
return V_29 ;
switch ( V_20 -> V_23 ) {
case V_27 :
return F_34 ( V_2 , V_31 , V_20 -> V_24 ) ;
case V_28 :
return F_42 ( V_2 , V_31 , V_20 -> V_24 ) ;
default:
return - V_26 ;
}
}
