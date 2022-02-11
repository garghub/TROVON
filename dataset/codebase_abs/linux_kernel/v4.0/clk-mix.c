static unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = ( 1 << V_2 -> V_4 . V_5 ) - 1 ;
unsigned int V_6 = 0 ;
struct V_7 * V_8 ;
if ( V_2 -> V_9 & V_10 )
return V_3 ;
if ( V_2 -> V_9 & V_11 )
return 1 << V_3 ;
if ( V_2 -> V_12 ) {
for ( V_8 = V_2 -> V_12 ; V_8 -> div ; V_8 ++ )
if ( V_8 -> div > V_6 )
V_6 = V_8 -> div ;
return V_6 ;
}
return V_3 + 1 ;
}
static unsigned int F_2 ( struct V_1 * V_2 , unsigned int V_13 )
{
struct V_7 * V_8 ;
if ( V_2 -> V_9 & V_10 )
return V_13 ;
if ( V_2 -> V_9 & V_11 )
return 1 << V_13 ;
if ( V_2 -> V_12 ) {
for ( V_8 = V_2 -> V_12 ; V_8 -> div ; V_8 ++ )
if ( V_8 -> V_13 == V_13 )
return V_8 -> div ;
if ( V_8 -> div == 0 )
return 0 ;
}
return V_13 + 1 ;
}
static unsigned int F_3 ( struct V_1 * V_2 , unsigned int V_13 )
{
int V_14 = F_4 ( V_2 -> V_15 . V_16 ) ;
int V_17 ;
if ( V_2 -> V_18 & V_19 )
return F_5 ( V_13 ) - 1 ;
if ( V_2 -> V_18 & V_20 )
return V_13 - 1 ;
if ( V_2 -> V_21 ) {
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ )
if ( V_2 -> V_21 [ V_17 ] == V_13 )
return V_17 ;
if ( V_17 == V_14 )
return 0 ;
}
return V_13 ;
}
static unsigned int F_6 ( struct V_1 * V_2 , unsigned int div )
{
struct V_7 * V_8 ;
if ( V_2 -> V_9 & V_10 )
return div ;
if ( V_2 -> V_9 & V_11 )
return F_7 ( div ) ;
if ( V_2 -> V_12 ) {
for ( V_8 = V_2 -> V_12 ; V_8 -> div ; V_8 ++ )
if ( V_8 -> div == div )
return V_8 -> V_13 ;
if ( V_8 -> div == 0 )
return 0 ;
}
return div - 1 ;
}
static unsigned int F_8 ( struct V_1 * V_2 , unsigned int V_22 )
{
if ( V_2 -> V_21 )
return V_2 -> V_21 [ V_22 ] ;
return V_22 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
unsigned int V_25 )
{
int V_17 ;
struct V_23 * V_26 ;
struct V_16 * V_27 , * V_16 ;
unsigned long V_28 ;
V_16 = V_2 -> V_15 . V_16 ;
for ( V_17 = 0 ; V_17 < V_25 ; V_17 ++ ) {
V_26 = & V_24 [ V_17 ] ;
V_27 = F_10 ( V_16 , V_26 -> V_29 ) ;
V_28 = F_11 ( V_27 ) ;
if ( V_28 % V_26 -> V_30 ) {
V_26 -> V_31 = 0 ;
} else {
V_26 -> V_32 = V_28 / V_26 -> V_30 ;
V_26 -> V_31 = 1 ;
}
}
}
static int F_12 ( struct V_1 * V_2 , T_1 V_33 , T_1 V_34 ,
unsigned int V_35 , unsigned int V_36 )
{
struct V_37 * V_38 = & V_2 -> V_4 ;
T_2 V_39 , V_40 ;
T_1 V_41 , V_42 ;
int V_43 , V_44 = 50 ;
unsigned long V_45 = 0 ;
if ( ! V_35 && ! V_36 )
return - V_46 ;
if ( V_2 -> V_47 )
F_13 ( V_2 -> V_47 , V_45 ) ;
if ( V_2 -> type == V_48
|| V_2 -> type == V_49 )
V_41 = F_14 ( V_38 -> V_50 ) ;
else
V_41 = F_14 ( V_38 -> V_51 ) ;
if ( V_36 ) {
V_39 = V_38 -> V_5 ;
V_40 = V_38 -> V_52 ;
V_41 &= ~ F_15 ( V_39 , V_40 ) ;
V_41 |= F_16 ( V_34 , V_39 , V_40 ) ;
}
if ( V_35 ) {
V_39 = V_38 -> V_53 ;
V_40 = V_38 -> V_54 ;
V_41 &= ~ F_15 ( V_39 , V_40 ) ;
V_41 |= F_16 ( V_33 , V_39 , V_40 ) ;
}
if ( V_2 -> type == V_48 ) {
F_17 ( V_41 , V_38 -> V_50 ) ;
} else if ( V_2 -> type == V_49 ) {
V_41 |= ( 1 << V_38 -> V_55 ) ;
F_17 ( V_41 , V_38 -> V_50 ) ;
do {
V_42 = F_14 ( V_38 -> V_50 ) ;
V_44 -- ;
if ( ! ( V_42 & ( 1 << V_38 -> V_55 ) ) )
break;
} while ( V_44 );
if ( V_44 == 0 ) {
F_18 ( L_1 ,
V_56 , F_19 ( V_2 -> V_15 . V_16 ) ) ;
V_43 = - V_57 ;
goto error;
}
} else {
V_42 = F_14 ( V_38 -> V_50 ) ;
V_42 |= 1 << V_38 -> V_55 ;
F_17 ( V_42 , V_38 -> V_50 ) ;
F_17 ( V_41 , V_38 -> V_51 ) ;
V_42 &= ~ ( 1 << V_38 -> V_55 ) ;
}
V_43 = 0 ;
error:
if ( V_2 -> V_47 )
F_20 ( V_2 -> V_47 , V_45 ) ;
return V_43 ;
}
static long F_21 ( struct V_58 * V_15 , unsigned long V_30 ,
unsigned long V_59 ,
unsigned long V_60 ,
unsigned long * V_61 ,
struct V_58 * * V_62 )
{
struct V_1 * V_2 = F_22 ( V_15 ) ;
struct V_23 * V_26 ;
struct V_16 * V_27 , * V_63 , * V_64 ;
unsigned long V_28 , V_65 , V_66 , V_67 ;
unsigned long V_68 , V_69 ;
T_1 V_70 ;
unsigned int div ;
int V_17 , V_71 ;
V_64 = V_15 -> V_16 ;
V_27 = NULL ;
V_66 = 0 ;
V_67 = 0 ;
V_69 = V_30 ;
V_63 = NULL ;
if ( V_2 -> V_24 ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_25 ; V_17 ++ ) {
V_26 = & V_2 -> V_24 [ V_17 ] ;
if ( V_26 -> V_31 == 0 )
continue;
V_27 = F_10 ( V_64 ,
V_26 -> V_29 ) ;
V_28 = F_11 ( V_27 ) ;
V_65 = V_28 / V_26 -> V_32 ;
V_68 = abs ( V_65 - V_30 ) ;
if ( V_63 == NULL || V_68 < V_69 ) {
V_63 = V_27 ;
V_67 = V_28 ;
V_66 = V_65 ;
V_69 = V_68 ;
if ( V_69 == 0 )
goto V_72;
}
}
} else {
for ( V_17 = 0 ; V_17 < F_4 ( V_64 ) ; V_17 ++ ) {
V_27 = F_10 ( V_64 , V_17 ) ;
V_28 = F_11 ( V_27 ) ;
V_70 = F_1 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
div = F_2 ( V_2 , V_71 ) ;
V_65 = V_28 / div ;
V_68 = abs ( V_65 - V_30 ) ;
if ( V_63 == NULL || V_68 < V_69 ) {
V_63 = V_27 ;
V_67 = V_28 ;
V_66 = V_65 ;
V_69 = V_68 ;
if ( V_69 == 0 )
goto V_72;
}
}
}
}
V_72:
* V_61 = V_67 ;
* V_62 = F_23 ( V_63 ) ;
return V_66 ;
}
static int F_24 ( struct V_58 * V_15 ,
unsigned long V_30 ,
unsigned long V_28 ,
T_2 V_73 )
{
struct V_1 * V_2 = F_22 ( V_15 ) ;
unsigned int div ;
T_1 V_34 , V_33 ;
div = V_28 / V_30 ;
V_34 = F_6 ( V_2 , div ) ;
V_33 = F_8 ( V_2 , V_73 ) ;
return F_12 ( V_2 , V_33 , V_34 , 1 , 1 ) ;
}
static T_2 F_25 ( struct V_58 * V_15 )
{
struct V_1 * V_2 = F_22 ( V_15 ) ;
struct V_37 * V_38 = & V_2 -> V_4 ;
unsigned long V_45 = 0 ;
T_1 V_41 = 0 ;
T_2 V_39 , V_40 ;
T_1 V_33 ;
if ( V_2 -> V_47 )
F_13 ( V_2 -> V_47 , V_45 ) ;
if ( V_2 -> type == V_48
|| V_2 -> type == V_49 )
V_41 = F_14 ( V_38 -> V_50 ) ;
else
V_41 = F_14 ( V_38 -> V_51 ) ;
if ( V_2 -> V_47 )
F_20 ( V_2 -> V_47 , V_45 ) ;
V_39 = V_2 -> V_4 . V_53 ;
V_40 = V_2 -> V_4 . V_54 ;
V_33 = F_26 ( V_41 , V_39 , V_40 ) ;
return F_3 ( V_2 , V_33 ) ;
}
static unsigned long F_27 ( struct V_58 * V_15 ,
unsigned long V_28 )
{
struct V_1 * V_2 = F_22 ( V_15 ) ;
struct V_37 * V_38 = & V_2 -> V_4 ;
unsigned long V_45 = 0 ;
T_1 V_41 = 0 ;
T_2 V_39 , V_40 ;
unsigned int div ;
if ( V_2 -> V_47 )
F_13 ( V_2 -> V_47 , V_45 ) ;
if ( V_2 -> type == V_48
|| V_2 -> type == V_49 )
V_41 = F_14 ( V_38 -> V_50 ) ;
else
V_41 = F_14 ( V_38 -> V_51 ) ;
if ( V_2 -> V_47 )
F_20 ( V_2 -> V_47 , V_45 ) ;
V_39 = V_2 -> V_4 . V_5 ;
V_40 = V_2 -> V_4 . V_52 ;
div = F_2 ( V_2 , F_26 ( V_41 , V_39 , V_40 ) ) ;
return V_28 / div ;
}
static int F_28 ( struct V_58 * V_15 , T_2 V_73 )
{
struct V_1 * V_2 = F_22 ( V_15 ) ;
struct V_23 * V_26 ;
int V_17 ;
T_1 V_34 , V_33 ;
if ( V_2 -> V_24 ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_25 ; V_17 ++ ) {
V_26 = & V_2 -> V_24 [ V_17 ] ;
if ( V_26 -> V_31 == 0 )
continue;
if ( V_26 -> V_29 == V_73 )
break;
}
if ( V_17 < V_2 -> V_25 ) {
V_34 = F_6 ( V_2 , V_26 -> V_32 ) ;
V_33 = F_8 ( V_2 , V_26 -> V_29 ) ;
} else
return - V_46 ;
} else {
V_33 = F_8 ( V_2 , V_73 ) ;
V_34 = 0 ;
}
return F_12 ( V_2 , V_33 , V_34 , 1 , V_34 ? 1 : 0 ) ;
}
static int F_29 ( struct V_58 * V_15 , unsigned long V_30 ,
unsigned long V_61 )
{
struct V_1 * V_2 = F_22 ( V_15 ) ;
struct V_23 * V_26 ;
unsigned long V_28 ;
unsigned int V_74 ;
struct V_16 * V_64 , * V_27 ;
int V_17 ;
V_74 = V_61 / V_30 ;
V_64 = V_15 -> V_16 ;
if ( V_2 -> V_24 ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_25 ; V_17 ++ ) {
V_26 = & V_2 -> V_24 [ V_17 ] ;
if ( V_26 -> V_31 == 0 )
continue;
V_27 = F_10 ( V_64 ,
V_26 -> V_29 ) ;
V_28 = F_11 ( V_27 ) ;
if ( V_28 == V_61
&& V_26 -> V_32 == V_74 )
break;
}
if ( V_17 < V_2 -> V_25 )
return F_12 ( V_2 ,
F_8 ( V_2 , V_26 -> V_29 ) ,
F_6 ( V_2 , V_26 -> V_32 ) ,
1 , 1 ) ;
else
return - V_46 ;
} else {
for ( V_17 = 0 ; V_17 < F_4 ( V_64 ) ; V_17 ++ ) {
V_27 = F_10 ( V_64 , V_17 ) ;
V_28 = F_11 ( V_27 ) ;
if ( V_28 == V_61 )
break;
}
if ( V_17 < F_4 ( V_64 ) )
return F_12 ( V_2 , F_8 ( V_2 , V_17 ) ,
F_6 ( V_2 , V_74 ) , 1 , 1 ) ;
else
return - V_46 ;
}
}
static void F_30 ( struct V_58 * V_15 )
{
struct V_1 * V_2 = F_22 ( V_15 ) ;
if ( V_2 -> V_24 )
F_9 ( V_2 , V_2 -> V_24 , V_2 -> V_25 ) ;
}
struct V_16 * F_31 ( struct V_75 * V_76 ,
const char * V_77 ,
const char * * V_78 ,
T_2 V_14 ,
unsigned long V_45 ,
struct V_79 * V_80 ,
T_3 * V_47 )
{
struct V_1 * V_2 ;
struct V_16 * V_16 ;
struct V_81 V_82 ;
T_4 V_83 ;
V_2 = F_32 ( sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 ) {
F_18 ( L_2 ,
V_56 , V_77 ) ;
return F_33 ( - V_85 ) ;
}
V_82 . V_77 = V_77 ;
V_82 . V_45 = V_45 | V_86 ;
V_82 . V_78 = V_78 ;
V_82 . V_14 = V_14 ;
V_82 . V_87 = & V_88 ;
memcpy ( & V_2 -> V_4 , & V_80 -> V_4 , sizeof( V_80 -> V_4 ) ) ;
if ( V_80 -> V_24 ) {
V_83 = sizeof( * V_80 -> V_24 ) * V_80 -> V_25 ;
V_2 -> V_24 = F_32 ( V_83 , V_84 ) ;
if ( ! V_2 -> V_24 ) {
F_18 ( L_3 ,
V_56 , V_77 ) ;
F_34 ( V_2 ) ;
return F_33 ( - V_85 ) ;
}
memcpy ( V_2 -> V_24 , V_80 -> V_24 , V_83 ) ;
V_2 -> V_25 = V_80 -> V_25 ;
}
if ( V_80 -> V_21 ) {
V_83 = sizeof( T_1 ) * V_14 ;
V_2 -> V_21 = F_32 ( V_83 , V_84 ) ;
if ( ! V_2 -> V_21 ) {
F_18 ( L_4 ,
V_56 , V_77 ) ;
F_34 ( V_2 -> V_24 ) ;
F_34 ( V_2 ) ;
return F_33 ( - V_85 ) ;
}
memcpy ( V_2 -> V_21 , V_80 -> V_21 , V_83 ) ;
}
V_2 -> V_9 = V_80 -> V_9 ;
V_2 -> V_18 = V_80 -> V_18 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_15 . V_82 = & V_82 ;
if ( V_80 -> V_4 . V_55 >= 32 )
V_2 -> type = V_48 ;
else if ( V_80 -> V_4 . V_51 )
V_2 -> type = V_89 ;
else
V_2 -> type = V_49 ;
V_16 = F_35 ( V_76 , & V_2 -> V_15 ) ;
if ( F_36 ( V_16 ) ) {
F_34 ( V_2 -> V_21 ) ;
F_34 ( V_2 -> V_24 ) ;
F_34 ( V_2 ) ;
}
return V_16 ;
}
