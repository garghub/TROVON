static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
F_2 ( L_1 , V_4 ) ;
V_4 -> V_6 = 0 ;
if ( ! V_2 -> V_7 )
V_2 -> V_8 = V_9 ;
if ( NULL == V_5 )
V_5 = V_4 ;
if ( V_9 == V_2 -> V_8 ) {
F_2 ( L_2 , V_4 , V_5 ) ;
F_3 ( F_4 ( 5 ) , F_5 ( V_4 ) ) ;
F_3 ( F_6 ( 5 ) , F_5 ( V_5 ) ) ;
V_2 -> V_8 = V_10 ;
} else {
F_2 ( L_3 , V_4 , V_5 ) ;
F_3 ( F_4 ( 5 ) , F_5 ( V_5 ) ) ;
F_3 ( F_6 ( 5 ) , F_5 ( V_4 ) ) ;
V_2 -> V_8 = V_9 ;
}
F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_11 . V_12 , V_13 + V_14 ) ;
if ( ! V_2 -> V_7 )
F_9 ( V_2 ) ;
return 0 ;
}
int F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 -> V_20 ;
struct V_3 * V_4 = F_11 ( V_16 , struct V_3 , V_16 ) ;
V_18 -> V_21 = NULL ;
V_4 -> V_22 = F_1 ;
return 0 ;
}
int F_12 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = F_11 ( V_16 , struct V_3 , V_16 ) ;
struct V_23 * V_24 = F_13 ( V_16 , 0 ) ;
unsigned int V_25 , V_26 , V_27 ;
F_2 ( L_4 , V_4 ) ;
V_26 = V_28 ;
V_25 = V_2 -> V_29 . V_30 ;
V_27 = V_25 * V_26 ;
if ( F_14 ( V_16 , 0 ) < V_27 )
return - V_31 ;
F_15 ( V_16 , 0 , V_27 ) ;
V_16 -> V_32 . V_33 = V_2 -> V_33 ;
return F_16 ( V_2 -> V_34 , & V_18 -> V_35 , V_24 -> V_36 , V_24 -> V_37 ,
F_17 ( V_4 ) ) ;
}
int F_18 ( struct V_19 * V_38 , const struct V_39 * V_40 ,
unsigned int * V_41 , unsigned int * V_42 ,
unsigned int V_43 [] , void * V_44 [] )
{
struct V_17 * V_18 = V_38 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_27 = V_28 * V_2 -> V_29 . V_30 ;
if ( 0 == * V_41 )
* V_41 = V_2 -> V_29 . V_45 ;
* V_41 = F_19 ( V_27 , * V_41 ) ;
if ( * V_41 < 3 )
* V_41 = 3 ;
* V_42 = 1 ;
V_43 [ 0 ] = V_27 ;
V_44 [ 0 ] = V_2 -> V_46 ;
return 0 ;
}
int F_20 ( struct V_19 * V_47 , unsigned int V_48 )
{
struct V_17 * V_18 = V_47 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
if ( F_21 ( & V_2 -> V_49 ) && V_2 -> V_40 -> V_50 ) {
struct V_3 * V_4 , * V_51 ;
F_22 (buf, tmp, &dmaq->queue, entry) {
F_23 ( & V_4 -> V_52 ) ;
F_24 ( & V_4 -> V_16 , V_53 ) ;
}
if ( V_18 -> V_21 ) {
F_24 ( & V_18 -> V_21 -> V_16 , V_53 ) ;
V_18 -> V_21 = NULL ;
}
return - V_54 ;
}
V_18 -> V_55 = 0 ;
return 0 ;
}
void F_25 ( struct V_19 * V_47 )
{
struct V_17 * V_18 = V_47 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
F_26 ( V_2 ) ;
F_27 ( V_2 , V_18 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
F_29 ( V_56 , 0x00 ) ;
F_29 ( V_57 , 0x6c ) ;
F_29 ( V_58 , ( V_28 - 1 ) ) ;
F_29 ( V_59 , ( ( V_2 -> V_29 . V_30 - 1 ) & 0xff ) ) ;
F_29 ( V_60 , ( ( ( V_2 -> V_29 . V_30 - 1 ) >> 8 ) & 0xff ) ) ;
F_29 ( V_61 ,
( ( ( ( V_2 -> V_29 . V_30 - 1 ) >> 16 ) & 0x3f ) | 0x00 ) ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 )
{
if ( V_62 < 2 )
V_62 = 2 ;
if ( V_62 > V_63 )
V_62 = V_63 ;
if ( V_64 < 4 )
V_64 = 4 ;
if ( V_64 > 312 )
V_64 = 312 ;
V_2 -> V_29 . V_45 = V_62 ;
V_2 -> V_29 . V_30 = V_64 ;
F_31 ( & V_2 -> V_11 . V_65 ) ;
F_32 ( & V_2 -> V_11 . V_12 ) ;
V_2 -> V_11 . V_12 . V_66 = V_67 ;
V_2 -> V_11 . V_12 . V_68 = ( unsigned long ) ( & V_2 -> V_11 ) ;
V_2 -> V_11 . V_2 = V_2 ;
V_2 -> V_11 . V_69 = 1 ;
V_2 -> V_7 = 0 ;
F_33 ( V_2 -> V_34 , & V_2 -> V_11 . V_35 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
F_2 ( L_5 ) ;
if ( ! V_2 -> V_7 )
return 0 ;
switch ( V_70 [ V_2 -> V_71 ] . V_72 ) {
case V_73 :
F_29 ( V_57 , 0x6c ) ;
V_2 -> V_7 = 0 ;
break;
case V_74 :
F_29 ( V_75 , 0x40 ) ;
V_2 -> V_7 = 0 ;
break;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
F_2 ( L_6 ) ;
if ( F_34 ( V_2 -> V_7 ) )
return 0 ;
F_29 ( V_59 , ( V_2 -> V_29 . V_30 - 1 ) & 0xff ) ;
F_29 ( V_60 ,
( ( V_2 -> V_29 . V_30 - 1 ) >> 8 ) & 0xff ) ;
F_29 ( V_61 ,
( ( ( V_2 -> V_29 . V_30 - 1 ) >> 16 ) & 0x3f ) | 0x00 ) ;
F_3 ( F_35 ( 5 ) , V_28 ) ;
F_3 ( F_36 ( 5 ) , V_76 |
V_77 |
( V_2 -> V_11 . V_35 . V_24 >> 12 ) ) ;
F_29 ( V_56 , 0x00 ) ;
F_29 ( V_56 , 0x03 ) ;
F_29 ( V_56 , 0x00 ) ;
F_29 ( V_56 , 0x01 ) ;
F_29 ( V_56 , 0x00 ) ;
switch ( V_70 [ V_2 -> V_71 ] . V_72 ) {
case V_73 :
F_29 ( V_75 , 0x40 ) ;
F_29 ( V_57 , 0xec |
( V_70 [ V_2 -> V_71 ] . V_78 << 4 ) ) ;
break;
case V_74 :
F_29 ( V_75 , 0xd8 ) ;
F_29 ( V_57 , 0x6c |
( V_70 [ V_2 -> V_71 ] . V_78 << 4 ) ) ;
F_29 ( V_58 , 0xbc ) ;
F_29 ( V_56 , 0x02 ) ;
break;
}
V_2 -> V_7 = 1 ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 -> V_34 , & V_2 -> V_11 . V_35 ) ;
return 0 ;
}
void F_39 ( struct V_1 * V_2 , unsigned long V_79 )
{
enum V_80 V_33 ;
F_40 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_11 . V_21 ) {
V_33 = V_2 -> V_8 ;
if ( V_33 != V_9 ) {
if ( ( V_79 & 0x100000 ) != 0x000000 )
goto V_82;
} else {
if ( ( V_79 & 0x100000 ) != 0x100000 )
goto V_82;
}
F_41 ( V_2 , & V_2 -> V_11 , V_83 ) ;
}
F_42 ( V_2 , & V_2 -> V_11 ) ;
V_82:
F_43 ( & V_2 -> V_81 ) ;
}
