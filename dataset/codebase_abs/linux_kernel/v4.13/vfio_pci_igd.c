static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_1 V_4 , T_3 * V_5 , bool V_6 )
{
unsigned int V_7 = F_2 ( * V_5 ) - V_8 ;
void * V_9 = V_2 -> V_10 [ V_7 ] . V_11 ;
T_3 V_12 = * V_5 & V_13 ;
if ( V_12 >= V_2 -> V_10 [ V_7 ] . V_14 || V_6 )
return - V_15 ;
V_4 = F_3 ( V_4 , ( T_1 ) ( V_2 -> V_10 [ V_7 ] . V_14 - V_12 ) ) ;
if ( F_4 ( V_3 , V_9 + V_12 , V_4 ) )
return - V_16 ;
* V_5 += V_4 ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_17 * V_10 )
{
F_6 ( V_10 -> V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_4 * V_18 = ( T_4 * ) ( V_2 -> V_19 + V_20 ) ;
T_5 V_21 , V_14 ;
void * V_9 ;
int V_22 ;
V_22 = F_8 ( V_2 -> V_23 , V_20 , & V_21 ) ;
if ( V_22 )
return V_22 ;
if ( ! V_21 || ! ( ~ V_21 ) )
return - V_24 ;
V_9 = F_9 ( V_21 , V_25 , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
if ( memcmp ( V_9 , V_28 , 16 ) ) {
F_6 ( V_9 ) ;
return - V_15 ;
}
V_14 = F_10 ( * ( T_4 * ) ( V_9 + 16 ) ) ;
if ( ! V_14 ) {
F_6 ( V_9 ) ;
return - V_15 ;
}
V_14 *= 1024 ;
if ( V_14 != V_25 ) {
F_6 ( V_9 ) ;
V_9 = F_9 ( V_21 , V_14 , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
}
V_22 = F_11 ( V_2 ,
V_29 | V_30 ,
V_31 ,
& V_32 , V_14 , V_33 , V_9 ) ;
if ( V_22 ) {
F_6 ( V_9 ) ;
return V_22 ;
}
* V_18 = F_12 ( V_21 ) ;
memset ( V_2 -> V_34 + V_20 ,
V_35 , 4 ) ;
return V_22 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
char T_2 * V_3 , T_1 V_4 , T_3 * V_5 ,
bool V_6 )
{
unsigned int V_7 = F_2 ( * V_5 ) - V_8 ;
struct V_36 * V_23 = V_2 -> V_10 [ V_7 ] . V_11 ;
T_3 V_12 = * V_5 & V_13 ;
T_1 V_14 ;
int V_22 ;
if ( V_12 >= V_2 -> V_10 [ V_7 ] . V_14 || V_6 )
return - V_15 ;
V_14 = V_4 = F_3 ( V_4 , ( T_1 ) ( V_2 -> V_10 [ V_7 ] . V_14 - V_12 ) ) ;
if ( ( V_12 & 1 ) && V_14 ) {
T_6 V_37 ;
V_22 = F_14 ( V_23 , V_12 , & V_37 ) ;
if ( V_22 )
return F_15 ( V_22 ) ;
if ( F_4 ( V_3 + V_4 - V_14 , & V_37 , 1 ) )
return - V_16 ;
V_12 ++ ;
V_14 -- ;
}
if ( ( V_12 & 3 ) && V_14 > 2 ) {
T_7 V_37 ;
V_22 = F_16 ( V_23 , V_12 , & V_37 ) ;
if ( V_22 )
return F_15 ( V_22 ) ;
V_37 = F_17 ( V_37 ) ;
if ( F_4 ( V_3 + V_4 - V_14 , & V_37 , 2 ) )
return - V_16 ;
V_12 += 2 ;
V_14 -= 2 ;
}
while ( V_14 > 3 ) {
T_5 V_37 ;
V_22 = F_18 ( V_23 , V_12 , & V_37 ) ;
if ( V_22 )
return F_15 ( V_22 ) ;
V_37 = F_12 ( V_37 ) ;
if ( F_4 ( V_3 + V_4 - V_14 , & V_37 , 4 ) )
return - V_16 ;
V_12 += 4 ;
V_14 -= 4 ;
}
while ( V_14 >= 2 ) {
T_7 V_37 ;
V_22 = F_16 ( V_23 , V_12 , & V_37 ) ;
if ( V_22 )
return F_15 ( V_22 ) ;
V_37 = F_17 ( V_37 ) ;
if ( F_4 ( V_3 + V_4 - V_14 , & V_37 , 2 ) )
return - V_16 ;
V_12 += 2 ;
V_14 -= 2 ;
}
while ( V_14 ) {
T_6 V_37 ;
V_22 = F_14 ( V_23 , V_12 , & V_37 ) ;
if ( V_22 )
return F_15 ( V_22 ) ;
if ( F_4 ( V_3 + V_4 - V_14 , & V_37 , 1 ) )
return - V_16 ;
V_12 ++ ;
V_14 -- ;
}
* V_5 += V_4 ;
return V_4 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_17 * V_10 )
{
struct V_36 * V_23 = V_10 -> V_11 ;
F_20 ( V_23 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_36 * V_38 , * V_39 ;
int V_22 ;
V_38 = F_22 ( 0 , 0 , F_23 ( 0 , 0 ) ) ;
if ( ! V_38 )
return - V_24 ;
if ( V_38 -> V_40 != V_29 ||
V_38 -> V_41 != ( V_42 << 8 ) ) {
F_20 ( V_38 ) ;
return - V_15 ;
}
V_22 = F_11 ( V_2 ,
V_29 | V_30 ,
V_43 ,
& V_44 , V_38 -> V_45 ,
V_33 , V_38 ) ;
if ( V_22 ) {
F_20 ( V_38 ) ;
return V_22 ;
}
V_39 = F_22 ( 0 , 0 , F_23 ( 0x1f , 0 ) ) ;
if ( ! V_39 )
return - V_24 ;
if ( V_39 -> V_40 != V_29 ||
V_39 -> V_41 != ( V_46 << 8 ) ) {
F_20 ( V_39 ) ;
return - V_15 ;
}
V_22 = F_11 ( V_2 ,
V_29 | V_30 ,
V_47 ,
& V_44 , V_39 -> V_45 ,
V_33 , V_39 ) ;
if ( V_22 ) {
F_20 ( V_39 ) ;
return V_22 ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_7 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_21 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
