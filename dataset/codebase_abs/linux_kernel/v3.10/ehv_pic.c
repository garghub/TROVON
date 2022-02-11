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
return V_16 ;
}
static unsigned int F_15 ( unsigned int type )
{
switch ( type & V_17 ) {
case V_18 :
return F_16 ( V_19 ) |
F_16 ( V_20 ) ;
case V_21 :
case V_22 :
return F_16 ( V_19 ) |
F_16 ( V_23 ) ;
case V_24 :
return F_16 ( V_25 ) |
F_16 ( V_20 ) ;
case V_26 :
default:
return F_16 ( V_25 ) |
F_16 ( V_23 ) ;
}
}
int F_17 ( struct V_1 * V_2 , unsigned int V_27 )
{
unsigned int V_3 = F_2 ( V_2 -> V_4 ) ;
struct V_28 * V_29 = F_18 ( V_2 -> V_4 ) ;
unsigned int V_30 , V_31 , V_32 , V_11 , V_12 ;
unsigned long V_14 ;
if ( V_27 == V_33 )
V_27 = V_26 ;
F_19 ( V_29 ) ;
F_20 ( V_29 , V_27 ) ;
if ( V_27 & ( V_24 | V_26 ) )
F_21 ( V_29 ) ;
V_30 = F_15 ( V_27 ) ;
F_11 ( & V_15 , V_14 ) ;
F_12 ( V_3 , & V_31 , & V_11 , & V_12 ) ;
V_32 = V_31 & ~ ( F_16 ( V_34 ) |
F_16 ( V_35 ) ) ;
V_32 |= V_30 ;
V_11 = 8 ;
F_13 ( V_3 , V_30 , V_11 , V_12 ) ;
F_14 ( & V_15 , V_14 ) ;
return 0 ;
}
unsigned int F_22 ( void )
{
int V_4 ;
F_23 ( V_36 == NULL ) ;
if ( V_36 -> V_37 )
V_4 = F_24 ( V_38 ) ;
else
F_25 ( 0 , & V_4 ) ;
if ( V_4 == 0xFFFF )
return V_39 ;
return F_26 ( V_36 -> V_40 , V_4 ) ;
}
static int F_27 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
return V_42 -> V_45 == NULL || V_42 -> V_45 == V_44 ;
}
static int F_28 ( struct V_41 * V_42 , unsigned int V_46 ,
T_1 V_47 )
{
struct V_48 * V_48 = V_42 -> V_49 ;
struct V_50 * V_51 ;
V_51 = & V_48 -> V_52 ;
if ( V_5 )
if ( V_53 [ V_47 ] & V_54 )
V_51 = & V_55 ;
F_29 ( V_46 , V_51 ) ;
F_30 ( V_46 , V_51 , V_56 ) ;
F_31 ( V_46 , V_33 ) ;
return 0 ;
}
static int F_32 ( struct V_41 * V_42 , struct V_43 * V_57 ,
const T_2 * V_58 , unsigned int V_59 ,
T_1 * V_60 , unsigned int * V_61 )
{
static unsigned char V_62 [ 4 ] = {
V_21 ,
V_18 ,
V_26 ,
V_24 ,
} ;
* V_60 = V_58 [ 0 ] ;
if ( V_59 > 1 ) {
V_53 [ V_58 [ 0 ] ] = V_58 [ 1 ] ;
* V_61 = V_62 [ V_58 [ 1 ] &
~ V_54 ] ;
} else {
* V_61 = V_33 ;
}
return 0 ;
}
void T_3 F_33 ( void )
{
struct V_43 * V_63 , * V_64 ;
struct V_48 * V_48 ;
int V_37 = 1 ;
V_63 = F_34 ( NULL , NULL , L_1 ) ;
if ( ! V_63 ) {
F_35 ( L_2 ) ;
return;
}
if ( ! F_36 ( V_63 , L_3 , NULL ) )
V_37 = 0 ;
V_48 = F_37 ( sizeof( struct V_48 ) , V_65 ) ;
if ( ! V_48 ) {
F_38 ( V_63 ) ;
return;
}
V_48 -> V_40 = F_39 ( V_63 , V_66 ,
& V_67 , V_48 ) ;
if ( ! V_48 -> V_40 ) {
F_38 ( V_63 ) ;
F_40 ( V_48 ) ;
return;
}
V_64 = F_34 ( NULL , NULL , L_4 ) ;
if ( V_64 ) {
V_5 = F_41 ( V_64 , 0 ) ;
if ( ! V_5 )
F_35 ( L_5 ) ;
F_38 ( V_64 ) ;
}
V_48 -> V_52 = V_68 ;
V_48 -> V_52 . V_69 = F_9 ;
V_48 -> V_37 = V_37 ;
V_36 = V_48 ;
F_42 ( V_36 -> V_40 ) ;
}
