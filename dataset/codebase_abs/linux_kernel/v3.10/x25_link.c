static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_4 + V_2 -> V_5 ) ;
}
static void F_3 ( unsigned long V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_6 ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_3 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_8 ( & V_2 -> V_3 ) ;
}
void F_9 ( struct V_7 * V_8 , struct V_1 * V_2 ,
unsigned short V_9 )
{
struct V_7 * V_10 ;
int V_11 ;
switch ( V_9 ) {
case V_12 :
V_11 = ! F_7 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_13 = V_14 ;
if ( V_11 )
F_10 ( V_2 ) ;
break;
case V_15 :
F_5 ( V_2 ) ;
V_2 -> V_13 = V_14 ;
break;
case V_16 :
if ( ! F_11 ( V_8 , V_17 + 4 ) )
break;
F_12 ( V_18 L_1 ,
V_8 -> V_19 [ 3 ] , V_8 -> V_19 [ 4 ] ,
V_8 -> V_19 [ 5 ] , V_8 -> V_19 [ 6 ] ) ;
break;
default:
F_12 ( V_18 L_2 ,
V_9 ) ;
break;
}
if ( V_2 -> V_13 == V_14 )
while ( ( V_10 = F_13 ( & V_2 -> V_20 ) ) != NULL )
F_14 ( V_10 , V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned char * V_21 ;
int V_22 = V_23 + V_17 + 2 ;
struct V_7 * V_8 = F_15 ( V_22 , V_24 ) ;
if ( ! V_8 )
return;
F_16 ( V_8 , V_23 ) ;
V_21 = F_17 ( V_8 , V_17 + 2 ) ;
* V_21 ++ = V_2 -> V_25 ? V_26 : V_27 ;
* V_21 ++ = 0x00 ;
* V_21 ++ = V_12 ;
* V_21 ++ = 0x00 ;
* V_21 ++ = 0 ;
V_8 -> V_28 = NULL ;
F_14 ( V_8 , V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned char * V_21 ;
int V_22 = V_23 + V_17 ;
struct V_7 * V_8 = F_15 ( V_22 , V_24 ) ;
if ( ! V_8 )
return;
F_16 ( V_8 , V_23 ) ;
V_21 = F_17 ( V_8 , V_17 ) ;
* V_21 ++ = V_2 -> V_25 ? V_26 : V_27 ;
* V_21 ++ = 0x00 ;
* V_21 ++ = V_15 ;
V_8 -> V_28 = NULL ;
F_14 ( V_8 , V_2 ) ;
}
void F_18 ( struct V_1 * V_2 , unsigned int V_29 ,
unsigned char V_30 )
{
unsigned char * V_21 ;
int V_22 = V_23 + V_17 + 2 ;
struct V_7 * V_8 = F_15 ( V_22 , V_24 ) ;
if ( ! V_8 )
return;
F_16 ( V_8 , V_23 ) ;
V_21 = F_17 ( V_8 , V_17 + 2 ) ;
* V_21 ++ = ( ( V_29 >> 8 ) & 0x0F ) | ( V_2 -> V_25 ?
V_26 :
V_27 ) ;
* V_21 ++ = ( V_29 >> 0 ) & 0xFF ;
* V_21 ++ = V_31 ;
* V_21 ++ = V_30 ;
* V_21 ++ = 0x00 ;
V_8 -> V_28 = NULL ;
F_14 ( V_8 , V_2 ) ;
}
void F_19 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
switch ( V_2 -> V_13 ) {
case V_32 :
F_20 ( & V_2 -> V_20 , V_8 ) ;
V_2 -> V_13 = V_33 ;
F_21 ( V_2 ) ;
break;
case V_33 :
case V_34 :
F_20 ( & V_2 -> V_20 , V_8 ) ;
break;
case V_14 :
F_14 ( V_8 , V_2 ) ;
break;
}
}
void F_22 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_13 ) {
case V_32 :
V_2 -> V_13 = V_34 ;
break;
case V_33 :
F_4 ( V_2 ) ;
V_2 -> V_13 = V_34 ;
F_1 ( V_2 ) ;
break;
}
}
void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_13 = V_32 ;
F_24 ( V_2 ) ;
}
void F_25 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_26 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return;
F_27 ( & V_2 -> V_20 ) ;
F_28 ( & V_2 -> V_3 , F_3 , ( unsigned long ) V_2 ) ;
F_29 ( V_36 ) ;
V_2 -> V_36 = V_36 ;
V_2 -> V_13 = V_32 ;
V_2 -> V_25 = 0 ;
V_2 -> V_37 = V_38 |
V_39 |
V_40 |
V_41 ;
V_2 -> V_5 = V_42 ;
F_30 ( & V_2 -> V_43 , 1 ) ;
F_31 ( & V_44 ) ;
F_32 ( & V_2 -> V_45 , & V_46 ) ;
F_33 ( & V_44 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_20 ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_45 . V_47 ) {
F_36 ( & V_2 -> V_45 ) ;
F_37 ( V_2 ) ;
}
}
void F_38 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_48 * V_49 , * V_50 ;
F_31 ( & V_44 ) ;
F_39 (entry, tmp, &x25_neigh_list) {
V_2 = F_40 ( V_49 , struct V_1 , V_45 ) ;
if ( V_2 -> V_36 == V_36 ) {
F_34 ( V_2 ) ;
F_41 ( V_36 ) ;
}
}
F_33 ( & V_44 ) ;
}
struct V_1 * F_42 ( struct V_35 * V_36 )
{
struct V_1 * V_2 , * V_51 = NULL ;
struct V_48 * V_49 ;
F_43 ( & V_44 ) ;
F_44 (entry, &x25_neigh_list) {
V_2 = F_40 ( V_49 , struct V_1 , V_45 ) ;
if ( V_2 -> V_36 == V_36 ) {
V_51 = V_2 ;
break;
}
}
if ( V_51 )
F_45 ( V_51 ) ;
F_46 ( & V_44 ) ;
return V_51 ;
}
int F_47 ( unsigned int V_52 , void T_1 * V_53 )
{
struct V_54 V_55 ;
struct V_1 * V_2 ;
struct V_35 * V_36 ;
int V_56 = - V_57 ;
if ( V_52 != V_58 && V_52 != V_59 )
goto V_60;
V_56 = - V_61 ;
if ( F_48 ( & V_55 , V_53 , sizeof( V_55 ) ) )
goto V_60;
V_56 = - V_57 ;
if ( ( V_36 = F_49 ( V_55 . V_62 ) ) == NULL )
goto V_60;
if ( ( V_2 = F_42 ( V_36 ) ) == NULL )
goto V_63;
F_41 ( V_36 ) ;
if ( V_52 == V_58 ) {
F_43 ( & V_44 ) ;
V_55 . V_25 = V_2 -> V_25 ;
V_55 . V_37 = V_2 -> V_37 ;
F_46 ( & V_44 ) ;
V_56 = F_50 ( V_53 , & V_55 ,
sizeof( V_55 ) ) ? - V_61 : 0 ;
} else {
V_56 = - V_57 ;
if ( ! ( V_55 . V_25 && V_55 . V_25 != 1 ) ) {
V_56 = 0 ;
F_31 ( & V_44 ) ;
V_2 -> V_25 = V_55 . V_25 ;
V_2 -> V_37 = V_55 . V_37 ;
F_33 ( & V_44 ) ;
}
}
F_37 ( V_2 ) ;
V_60:
return V_56 ;
V_63:
F_41 ( V_36 ) ;
goto V_60;
}
void T_2 F_51 ( void )
{
struct V_1 * V_2 ;
struct V_48 * V_49 , * V_50 ;
F_31 ( & V_44 ) ;
F_39 (entry, tmp, &x25_neigh_list) {
struct V_35 * V_36 ;
V_2 = F_40 ( V_49 , struct V_1 , V_45 ) ;
V_36 = V_2 -> V_36 ;
F_34 ( V_2 ) ;
F_41 ( V_36 ) ;
}
F_33 ( & V_44 ) ;
}
