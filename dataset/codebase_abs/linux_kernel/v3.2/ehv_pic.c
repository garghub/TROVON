void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 -> V_4 ) ;
F_3 ( V_3 , 0 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 -> V_4 ) ;
F_3 ( V_3 , 1 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 -> V_4 ) ;
F_6 ( V_3 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_5 + V_6 / 4 , 0 ) ;
}
int F_9 ( struct V_1 * V_2 , const struct V_7 * V_8 ,
bool V_9 )
{
unsigned int V_3 = F_2 ( V_2 -> V_4 ) ;
unsigned int V_10 , V_11 , V_12 ;
int V_13 = F_10 ( V_8 ) ;
unsigned long V_14 ;
F_11 ( & V_15 , V_14 ) ;
F_12 ( V_3 , & V_10 , & V_11 , & V_12 ) ;
F_13 ( V_3 , V_10 , V_11 , V_13 ) ;
F_14 ( & V_15 , V_14 ) ;
return 0 ;
}
static unsigned int F_15 ( unsigned int type )
{
switch ( type & V_16 ) {
case V_17 :
return F_16 ( V_18 ) |
F_16 ( V_19 ) ;
case V_20 :
case V_21 :
return F_16 ( V_18 ) |
F_16 ( V_22 ) ;
case V_23 :
return F_16 ( V_24 ) |
F_16 ( V_19 ) ;
case V_25 :
default:
return F_16 ( V_24 ) |
F_16 ( V_22 ) ;
}
}
int F_17 ( struct V_1 * V_2 , unsigned int V_26 )
{
unsigned int V_3 = F_2 ( V_2 -> V_4 ) ;
struct V_27 * V_28 = F_18 ( V_2 -> V_4 ) ;
unsigned int V_29 , V_30 , V_31 , V_11 , V_12 ;
unsigned long V_14 ;
if ( V_26 == V_32 )
V_26 = V_25 ;
F_19 ( V_28 ) ;
F_20 ( V_28 , V_26 ) ;
if ( V_26 & ( V_23 | V_25 ) )
F_21 ( V_28 ) ;
V_29 = F_15 ( V_26 ) ;
F_11 ( & V_15 , V_14 ) ;
F_12 ( V_3 , & V_30 , & V_11 , & V_12 ) ;
V_31 = V_30 & ~ ( F_16 ( V_33 ) |
F_16 ( V_34 ) ) ;
V_31 |= V_29 ;
V_11 = 8 ;
F_13 ( V_3 , V_29 , V_11 , V_12 ) ;
F_14 ( & V_15 , V_14 ) ;
return 0 ;
}
unsigned int F_22 ( void )
{
int V_4 ;
F_23 ( V_35 == NULL ) ;
if ( V_35 -> V_36 )
V_4 = F_24 ( V_37 ) ;
else
F_25 ( 0 , & V_4 ) ;
if ( V_4 == 0xFFFF )
return V_38 ;
return F_26 ( V_35 -> V_39 , V_4 ) ;
}
static int F_27 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
return V_41 -> V_44 == NULL || V_41 -> V_44 == V_43 ;
}
static int F_28 ( struct V_40 * V_41 , unsigned int V_45 ,
T_1 V_46 )
{
struct V_47 * V_47 = V_41 -> V_48 ;
struct V_49 * V_50 ;
V_50 = & V_47 -> V_51 ;
if ( V_5 )
if ( V_52 [ V_46 ] & V_53 )
V_50 = & V_54 ;
F_29 ( V_45 , V_50 ) ;
F_30 ( V_45 , V_50 , V_55 ) ;
F_31 ( V_45 , V_32 ) ;
return 0 ;
}
static int F_32 ( struct V_40 * V_41 , struct V_42 * V_56 ,
const T_2 * V_57 , unsigned int V_58 ,
T_1 * V_59 , unsigned int * V_60 )
{
static unsigned char V_61 [ 4 ] = {
V_20 ,
V_17 ,
V_25 ,
V_23 ,
} ;
* V_59 = V_57 [ 0 ] ;
if ( V_58 > 1 ) {
V_52 [ V_57 [ 0 ] ] = V_57 [ 1 ] ;
* V_60 = V_61 [ V_57 [ 1 ] &
~ V_53 ] ;
} else {
* V_60 = V_32 ;
}
return 0 ;
}
void T_3 F_33 ( void )
{
struct V_42 * V_62 , * V_63 ;
struct V_47 * V_47 ;
int V_36 = 1 ;
V_62 = F_34 ( NULL , NULL , L_1 ) ;
if ( ! V_62 ) {
F_35 ( L_2 ) ;
return;
}
if ( ! F_36 ( V_62 , L_3 , NULL ) )
V_36 = 0 ;
V_47 = F_37 ( sizeof( struct V_47 ) , V_64 ) ;
if ( ! V_47 ) {
F_38 ( V_62 ) ;
return;
}
V_47 -> V_39 = F_39 ( V_62 , V_65 ,
V_66 , & V_67 , 0 ) ;
if ( ! V_47 -> V_39 ) {
F_38 ( V_62 ) ;
F_40 ( V_47 ) ;
return;
}
V_63 = F_34 ( NULL , NULL , L_4 ) ;
if ( V_63 ) {
V_5 = F_41 ( V_63 , 0 ) ;
if ( ! V_5 )
F_35 ( L_5 ) ;
F_38 ( V_63 ) ;
}
V_47 -> V_39 -> V_48 = V_47 ;
V_47 -> V_51 = V_68 ;
V_47 -> V_51 . V_69 = F_9 ;
V_47 -> V_36 = V_36 ;
V_35 = V_47 ;
F_42 ( V_35 -> V_39 ) ;
}
