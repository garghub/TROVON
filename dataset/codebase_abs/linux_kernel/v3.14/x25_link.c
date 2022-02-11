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
F_12 ( L_1 ,
V_8 -> V_18 [ 3 ] , V_8 -> V_18 [ 4 ] ,
V_8 -> V_18 [ 5 ] , V_8 -> V_18 [ 6 ] ) ;
break;
default:
F_12 ( L_2 ,
V_9 ) ;
break;
}
if ( V_2 -> V_13 == V_14 )
while ( ( V_10 = F_13 ( & V_2 -> V_19 ) ) != NULL )
F_14 ( V_10 , V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned char * V_20 ;
int V_21 = V_22 + V_17 + 2 ;
struct V_7 * V_8 = F_15 ( V_21 , V_23 ) ;
if ( ! V_8 )
return;
F_16 ( V_8 , V_22 ) ;
V_20 = F_17 ( V_8 , V_17 + 2 ) ;
* V_20 ++ = V_2 -> V_24 ? V_25 : V_26 ;
* V_20 ++ = 0x00 ;
* V_20 ++ = V_12 ;
* V_20 ++ = 0x00 ;
* V_20 ++ = 0 ;
V_8 -> V_27 = NULL ;
F_14 ( V_8 , V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned char * V_20 ;
int V_21 = V_22 + V_17 ;
struct V_7 * V_8 = F_15 ( V_21 , V_23 ) ;
if ( ! V_8 )
return;
F_16 ( V_8 , V_22 ) ;
V_20 = F_17 ( V_8 , V_17 ) ;
* V_20 ++ = V_2 -> V_24 ? V_25 : V_26 ;
* V_20 ++ = 0x00 ;
* V_20 ++ = V_15 ;
V_8 -> V_27 = NULL ;
F_14 ( V_8 , V_2 ) ;
}
void F_18 ( struct V_1 * V_2 , unsigned int V_28 ,
unsigned char V_29 )
{
unsigned char * V_20 ;
int V_21 = V_22 + V_17 + 2 ;
struct V_7 * V_8 = F_15 ( V_21 , V_23 ) ;
if ( ! V_8 )
return;
F_16 ( V_8 , V_22 ) ;
V_20 = F_17 ( V_8 , V_17 + 2 ) ;
* V_20 ++ = ( ( V_28 >> 8 ) & 0x0F ) | ( V_2 -> V_24 ?
V_25 :
V_26 ) ;
* V_20 ++ = ( V_28 >> 0 ) & 0xFF ;
* V_20 ++ = V_30 ;
* V_20 ++ = V_29 ;
* V_20 ++ = 0x00 ;
V_8 -> V_27 = NULL ;
F_14 ( V_8 , V_2 ) ;
}
void F_19 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
switch ( V_2 -> V_13 ) {
case V_31 :
F_20 ( & V_2 -> V_19 , V_8 ) ;
V_2 -> V_13 = V_32 ;
F_21 ( V_2 ) ;
break;
case V_32 :
case V_33 :
F_20 ( & V_2 -> V_19 , V_8 ) ;
break;
case V_14 :
F_14 ( V_8 , V_2 ) ;
break;
}
}
void F_22 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_13 ) {
case V_31 :
V_2 -> V_13 = V_33 ;
break;
case V_32 :
F_4 ( V_2 ) ;
V_2 -> V_13 = V_33 ;
F_1 ( V_2 ) ;
break;
}
}
void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_13 = V_31 ;
F_24 ( V_2 ) ;
}
void F_25 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_26 ( sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 )
return;
F_27 ( & V_2 -> V_19 ) ;
F_28 ( & V_2 -> V_3 , F_3 , ( unsigned long ) V_2 ) ;
F_29 ( V_35 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_13 = V_31 ;
V_2 -> V_24 = 0 ;
V_2 -> V_36 = V_37 |
V_38 |
V_39 |
V_40 ;
V_2 -> V_5 = V_41 ;
F_30 ( & V_2 -> V_42 , 1 ) ;
F_31 ( & V_43 ) ;
F_32 ( & V_2 -> V_44 , & V_45 ) ;
F_33 ( & V_43 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_19 ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_44 . V_46 ) {
F_36 ( & V_2 -> V_44 ) ;
F_37 ( V_2 ) ;
}
}
void F_38 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_47 * V_48 , * V_49 ;
F_31 ( & V_43 ) ;
F_39 (entry, tmp, &x25_neigh_list) {
V_2 = F_40 ( V_48 , struct V_1 , V_44 ) ;
if ( V_2 -> V_35 == V_35 ) {
F_34 ( V_2 ) ;
F_41 ( V_35 ) ;
}
}
F_33 ( & V_43 ) ;
}
struct V_1 * F_42 ( struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_50 = NULL ;
struct V_47 * V_48 ;
F_43 ( & V_43 ) ;
F_44 (entry, &x25_neigh_list) {
V_2 = F_40 ( V_48 , struct V_1 , V_44 ) ;
if ( V_2 -> V_35 == V_35 ) {
V_50 = V_2 ;
break;
}
}
if ( V_50 )
F_45 ( V_50 ) ;
F_46 ( & V_43 ) ;
return V_50 ;
}
int F_47 ( unsigned int V_51 , void T_1 * V_52 )
{
struct V_53 V_54 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_55 = - V_56 ;
if ( V_51 != V_57 && V_51 != V_58 )
goto V_59;
V_55 = - V_60 ;
if ( F_48 ( & V_54 , V_52 , sizeof( V_54 ) ) )
goto V_59;
V_55 = - V_56 ;
if ( ( V_35 = F_49 ( V_54 . V_61 ) ) == NULL )
goto V_59;
if ( ( V_2 = F_42 ( V_35 ) ) == NULL )
goto V_62;
F_41 ( V_35 ) ;
if ( V_51 == V_57 ) {
F_43 ( & V_43 ) ;
V_54 . V_24 = V_2 -> V_24 ;
V_54 . V_36 = V_2 -> V_36 ;
F_46 ( & V_43 ) ;
V_55 = F_50 ( V_52 , & V_54 ,
sizeof( V_54 ) ) ? - V_60 : 0 ;
} else {
V_55 = - V_56 ;
if ( ! ( V_54 . V_24 && V_54 . V_24 != 1 ) ) {
V_55 = 0 ;
F_31 ( & V_43 ) ;
V_2 -> V_24 = V_54 . V_24 ;
V_2 -> V_36 = V_54 . V_36 ;
F_33 ( & V_43 ) ;
}
}
F_37 ( V_2 ) ;
V_59:
return V_55 ;
V_62:
F_41 ( V_35 ) ;
goto V_59;
}
void T_2 F_51 ( void )
{
struct V_1 * V_2 ;
struct V_47 * V_48 , * V_49 ;
F_31 ( & V_43 ) ;
F_39 (entry, tmp, &x25_neigh_list) {
struct V_34 * V_35 ;
V_2 = F_40 ( V_48 , struct V_1 , V_44 ) ;
V_35 = V_2 -> V_35 ;
F_34 ( V_2 ) ;
F_41 ( V_35 ) ;
}
F_33 ( & V_43 ) ;
}
