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
unsigned int V_28 , V_29 , V_30 , V_11 , V_12 ;
unsigned long V_14 ;
if ( V_27 == V_31 )
V_27 = V_26 ;
F_18 ( V_2 , V_27 ) ;
V_28 = F_15 ( V_27 ) ;
F_11 ( & V_15 , V_14 ) ;
F_12 ( V_3 , & V_29 , & V_11 , & V_12 ) ;
V_30 = V_29 & ~ ( F_16 ( V_32 ) |
F_16 ( V_33 ) ) ;
V_30 |= V_28 ;
V_11 = 8 ;
F_13 ( V_3 , V_28 , V_11 , V_12 ) ;
F_14 ( & V_15 , V_14 ) ;
return V_34 ;
}
unsigned int F_19 ( void )
{
int V_4 ;
F_20 ( V_35 == NULL ) ;
if ( V_35 -> V_36 )
V_4 = F_21 ( V_37 ) ;
else
F_22 ( 0 , & V_4 ) ;
if ( V_4 == 0xFFFF )
return V_38 ;
return F_23 ( V_35 -> V_39 , V_4 ) ;
}
static int F_24 ( struct V_40 * V_41 , struct V_42 * V_43 ,
enum V_44 V_45 )
{
return V_41 -> V_46 == NULL || V_41 -> V_46 == V_43 ;
}
static int F_25 ( struct V_40 * V_41 , unsigned int V_47 ,
T_1 V_48 )
{
struct V_49 * V_49 = V_41 -> V_50 ;
struct V_51 * V_52 ;
V_52 = & V_49 -> V_53 ;
if ( V_5 )
if ( V_54 [ V_48 ] & V_55 )
V_52 = & V_56 ;
F_26 ( V_47 , V_52 ) ;
F_27 ( V_47 , V_52 , V_57 ) ;
F_28 ( V_47 , V_31 ) ;
return 0 ;
}
static int F_29 ( struct V_40 * V_41 , struct V_42 * V_58 ,
const T_2 * V_59 , unsigned int V_60 ,
T_1 * V_61 , unsigned int * V_62 )
{
static unsigned char V_63 [ 4 ] = {
V_21 ,
V_18 ,
V_26 ,
V_24 ,
} ;
* V_61 = V_59 [ 0 ] ;
if ( V_60 > 1 ) {
V_54 [ V_59 [ 0 ] ] = V_59 [ 1 ] ;
* V_62 = V_63 [ V_59 [ 1 ] &
~ V_55 ] ;
} else {
* V_62 = V_31 ;
}
return 0 ;
}
void T_3 F_30 ( void )
{
struct V_42 * V_64 , * V_65 ;
struct V_49 * V_49 ;
int V_36 = 1 ;
V_64 = F_31 ( NULL , NULL , L_1 ) ;
if ( ! V_64 ) {
F_32 ( L_2 ) ;
return;
}
if ( ! F_33 ( V_64 , L_3 , NULL ) )
V_36 = 0 ;
V_49 = F_34 ( sizeof( struct V_49 ) , V_66 ) ;
if ( ! V_49 ) {
F_35 ( V_64 ) ;
return;
}
V_49 -> V_39 = F_36 ( V_64 , V_67 ,
& V_68 , V_49 ) ;
if ( ! V_49 -> V_39 ) {
F_35 ( V_64 ) ;
F_37 ( V_49 ) ;
return;
}
V_65 = F_31 ( NULL , NULL , L_4 ) ;
if ( V_65 ) {
V_5 = F_38 ( V_65 , 0 ) ;
if ( ! V_5 )
F_32 ( L_5 ) ;
F_35 ( V_65 ) ;
}
V_49 -> V_53 = V_69 ;
V_49 -> V_53 . V_70 = F_9 ;
V_49 -> V_36 = V_36 ;
V_35 = V_49 ;
F_39 ( V_35 -> V_39 ) ;
}
