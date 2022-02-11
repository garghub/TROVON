static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 , V_6 = V_4 -> V_7 & V_8 ;
struct V_9 * V_10 ;
switch ( V_6 ) {
case V_11 :
case V_12 :
case V_13 :
V_10 = & V_2 -> V_14 [ V_6 - 1 ] ;
if ( V_10 -> V_15 < V_10 -> V_16 )
return 1 ;
if ( V_4 -> free + V_4 -> V_17 >= V_2 -> V_18 )
return 1 ;
return 0 ;
case V_19 :
V_5 = V_2 -> V_20 . V_21 + V_2 -> V_22 -
V_2 -> V_20 . V_23 ;
if ( V_5 < V_2 -> V_24 )
return 1 ;
return 0 ;
case V_25 :
return 1 ;
case V_26 :
return 1 ;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_27 ,
struct V_28 * V_29 )
{
int V_30 = V_31 ;
if ( V_4 -> V_7 & V_32 )
return V_31 ;
if ( ! V_27 && F_1 ( V_2 , V_4 ) )
V_30 |= V_33 ;
if ( V_4 -> free + V_4 -> V_17 < V_29 -> V_34 )
return V_30 ;
if ( V_29 -> V_35 && V_4 -> V_7 & V_36 )
return V_30 ;
if ( V_4 -> free + V_4 -> V_17 == V_2 -> V_37 ) {
if ( ! V_29 -> V_38 )
return V_30 ;
} else if ( V_4 -> V_17 < V_2 -> V_39 )
return V_30 ;
V_29 -> V_40 = V_4 -> V_40 ;
return V_33 | V_41 ;
}
static const struct V_3 * F_3 ( struct V_1 * V_2 ,
int V_34 , int V_38 ,
int V_35 )
{
const struct V_3 * V_4 ;
struct V_9 * V_10 ;
struct V_28 V_29 ;
int V_42 , V_43 ;
V_10 = & V_2 -> V_14 [ V_13 - 1 ] ;
for ( V_43 = 0 ; V_43 < V_10 -> V_15 ; V_43 ++ ) {
V_4 = V_10 -> V_44 [ V_43 ] ;
if ( V_4 -> free + V_4 -> V_17 < V_34 )
continue;
if ( V_4 -> V_17 < V_2 -> V_39 )
continue;
return V_4 ;
}
F_4 (lprops, &c->uncat_list, list) {
if ( V_4 -> V_7 & V_32 )
continue;
if ( V_4 -> free + V_4 -> V_17 < V_34 )
continue;
if ( V_35 && ( V_4 -> V_7 & V_36 ) )
continue;
if ( V_4 -> V_17 < V_2 -> V_39 )
continue;
return V_4 ;
}
if ( V_2 -> V_45 >= V_2 -> V_46 )
return F_5 ( - V_47 ) ;
V_29 . V_34 = V_34 ;
V_29 . V_38 = V_38 ;
V_29 . V_40 = - 1 ;
V_29 . V_35 = V_35 ;
V_42 = F_6 ( V_2 , - 1 , V_2 -> V_48 ,
( V_49 ) F_2 ,
& V_29 ) ;
if ( V_42 )
return F_5 ( V_42 ) ;
F_7 ( V_29 . V_40 >= V_2 -> V_50 && V_29 . V_40 < V_2 -> V_51 ) ;
V_2 -> V_48 = V_29 . V_40 ;
V_4 = F_8 ( V_2 , V_29 . V_40 ) ;
if ( F_9 ( V_4 ) )
return V_4 ;
F_7 ( V_4 -> V_40 == V_29 . V_40 ) ;
F_7 ( V_4 -> free + V_4 -> V_17 >= V_34 ) ;
F_7 ( V_4 -> V_17 >= V_2 -> V_39 ||
( V_38 &&
V_4 -> free + V_4 -> V_17 == V_2 -> V_37 ) ) ;
F_7 ( ! ( V_4 -> V_7 & V_32 ) ) ;
F_7 ( ! V_35 || ! ( V_4 -> V_7 & V_36 ) ) ;
return V_4 ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_52 ,
int V_34 , int V_38 )
{
int V_42 = 0 , V_53 , V_35 = V_38 == 2 ? 1 : 0 ;
const struct V_3 * V_54 = NULL , * V_55 = NULL ;
struct V_9 * V_10 , * V_56 ;
F_11 ( V_2 ) ;
if ( V_38 ) {
int V_57 , V_58 = 0 ;
F_12 ( & V_2 -> V_59 ) ;
V_57 = V_2 -> V_20 . V_21 + V_2 -> V_60 ;
V_57 += V_2 -> V_22 - V_2 -> V_20 . V_23 ;
if ( V_2 -> V_61 . V_62 >= V_2 -> V_20 . V_63 ) {
V_58 = V_2 -> V_61 . V_62 - V_2 -> V_20 . V_63 ;
V_35 = 1 ;
}
F_13 ( & V_2 -> V_59 ) ;
if ( V_58 < V_57 ) {
V_54 = F_14 ( V_2 ) ;
if ( V_54 )
goto V_64;
V_54 = F_15 ( V_2 ) ;
if ( V_54 )
goto V_64;
} else
V_38 = 0 ;
} else {
F_12 ( & V_2 -> V_59 ) ;
V_35 = ( V_2 -> V_61 . V_62 >= V_2 -> V_20 . V_63 ) ;
F_13 ( & V_2 -> V_59 ) ;
}
V_10 = & V_2 -> V_14 [ V_11 - 1 ] ;
V_56 = & V_2 -> V_14 [ V_12 - 1 ] ;
if ( V_56 -> V_15 && ! V_35 ) {
V_55 = V_56 -> V_44 [ 0 ] ;
V_53 = V_55 -> free + V_55 -> V_17 ;
if ( V_53 < V_34 || V_53 < V_2 -> V_65 )
V_55 = NULL ;
}
if ( V_10 -> V_15 ) {
V_54 = V_10 -> V_44 [ 0 ] ;
if ( V_54 -> V_17 + V_54 -> free < V_34 )
V_54 = NULL ;
}
if ( V_55 && V_54 ) {
if ( V_55 -> free + V_55 -> V_17 >= V_54 -> free + V_54 -> V_17 )
V_54 = V_55 ;
} else if ( V_55 && ! V_54 )
V_54 = V_55 ;
if ( V_54 ) {
F_7 ( V_54 -> free + V_54 -> V_17 >= V_2 -> V_39 ) ;
goto V_64;
}
F_16 ( L_1 ) ;
V_54 = F_3 ( V_2 , V_34 , V_38 , V_35 ) ;
if ( F_9 ( V_54 ) ) {
V_42 = F_17 ( V_54 ) ;
goto V_66;
}
F_7 ( V_54 -> V_17 >= V_2 -> V_39 ||
( V_38 && V_54 -> free + V_54 -> V_17 == V_2 -> V_37 ) ) ;
V_64:
F_16 ( L_2 ,
V_54 -> V_40 , V_54 -> free , V_54 -> V_17 , V_54 -> V_7 ) ;
V_54 = F_18 ( V_2 , V_54 , V_67 , V_67 ,
V_54 -> V_7 | V_32 , 0 ) ;
if ( F_9 ( V_54 ) ) {
V_42 = F_17 ( V_54 ) ;
goto V_66;
}
memcpy ( V_52 , V_54 , sizeof( struct V_3 ) ) ;
V_66:
F_19 ( V_2 ) ;
return V_42 ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_27 ,
struct V_28 * V_29 )
{
int V_30 = V_31 ;
if ( V_4 -> V_7 & V_32 )
return V_31 ;
if ( ! V_27 && F_1 ( V_2 , V_4 ) )
V_30 |= V_33 ;
if ( V_4 -> V_7 & V_36 )
return V_30 ;
if ( V_4 -> free < V_29 -> V_34 )
return V_30 ;
if ( ! V_29 -> V_38 && V_4 -> free == V_2 -> V_37 )
return V_30 ;
if ( V_4 -> free + V_4 -> V_17 == V_2 -> V_37 && V_4 -> V_17 > 0 )
return V_30 ;
V_29 -> V_40 = V_4 -> V_40 ;
return V_33 | V_41 ;
}
static
const struct V_3 * F_21 ( struct V_1 * V_2 ,
int V_34 , int V_38 ,
int V_68 )
{
const struct V_3 * V_4 ;
struct V_9 * V_10 ;
struct V_28 V_29 ;
int V_42 , V_43 ;
if ( V_68 ) {
V_4 = F_22 ( V_2 ) ;
if ( V_4 && V_4 -> free >= V_34 )
return V_4 ;
}
if ( V_38 ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 )
return V_4 ;
}
if ( ! V_68 ) {
V_4 = F_22 ( V_2 ) ;
if ( V_4 && V_4 -> free >= V_34 )
return V_4 ;
}
V_10 = & V_2 -> V_14 [ V_11 - 1 ] ;
for ( V_43 = 0 ; V_43 < V_10 -> V_15 ; V_43 ++ ) {
V_4 = V_10 -> V_44 [ V_43 ] ;
if ( V_4 -> free >= V_34 )
return V_4 ;
}
F_4 (lprops, &c->uncat_list, list) {
if ( V_4 -> V_7 & V_32 )
continue;
if ( V_4 -> V_7 & V_36 )
continue;
if ( V_4 -> free >= V_34 )
return V_4 ;
}
if ( V_2 -> V_45 >= V_2 -> V_46 )
return F_5 ( - V_47 ) ;
V_29 . V_34 = V_34 ;
V_29 . V_38 = V_38 ;
V_29 . V_40 = - 1 ;
V_42 = F_6 ( V_2 , - 1 , V_2 -> V_48 ,
( V_49 ) F_20 ,
& V_29 ) ;
if ( V_42 )
return F_5 ( V_42 ) ;
F_7 ( V_29 . V_40 >= V_2 -> V_50 && V_29 . V_40 < V_2 -> V_51 ) ;
V_2 -> V_48 = V_29 . V_40 ;
V_4 = F_8 ( V_2 , V_29 . V_40 ) ;
if ( F_9 ( V_4 ) )
return V_4 ;
F_7 ( V_4 -> V_40 == V_29 . V_40 ) ;
F_7 ( V_4 -> free >= V_34 ) ;
F_7 ( ! ( V_4 -> V_7 & V_32 ) ) ;
F_7 ( ! ( V_4 -> V_7 & V_36 ) ) ;
return V_4 ;
}
int F_23 ( struct V_1 * V_2 , int V_34 , int * V_69 ,
int V_68 )
{
const struct V_3 * V_4 ;
int V_57 , V_58 , V_38 = 0 , V_42 , V_40 , V_7 ;
F_16 ( L_3 , V_34 ) ;
F_11 ( V_2 ) ;
F_12 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_61 . V_62 > V_2 -> V_20 . V_63 )
V_58 = V_2 -> V_61 . V_62 - V_2 -> V_20 . V_63 ;
else
V_58 = 0 ;
V_57 = V_2 -> V_20 . V_21 + V_2 -> V_22 + V_2 -> V_60 -
V_2 -> V_20 . V_23 ;
if ( V_58 < V_57 )
if ( V_2 -> V_20 . V_21 - V_2 -> V_20 . V_23 > 0 ) {
V_38 = 1 ;
V_2 -> V_20 . V_23 += 1 ;
}
F_13 ( & V_2 -> V_59 ) ;
V_4 = F_21 ( V_2 , V_34 , V_38 , V_68 ) ;
if ( F_9 ( V_4 ) ) {
V_42 = F_17 ( V_4 ) ;
goto V_66;
}
V_40 = V_4 -> V_40 ;
V_7 = V_4 -> V_7 | V_32 ;
V_4 = F_18 ( V_2 , V_4 , V_67 , V_67 , V_7 , 0 ) ;
if ( F_9 ( V_4 ) ) {
V_42 = F_17 ( V_4 ) ;
goto V_66;
}
if ( V_38 ) {
F_12 ( & V_2 -> V_59 ) ;
V_2 -> V_20 . V_23 -= 1 ;
F_13 ( & V_2 -> V_59 ) ;
}
* V_69 = V_2 -> V_37 - V_4 -> free ;
F_19 ( V_2 ) ;
if ( * V_69 == 0 ) {
V_42 = F_24 ( V_2 , V_40 ) ;
if ( V_42 )
return V_42 ;
}
F_16 ( L_4 , V_40 , V_2 -> V_37 - * V_69 ) ;
F_7 ( * V_69 <= V_2 -> V_37 - V_34 ) ;
return V_40 ;
V_66:
if ( V_38 ) {
F_12 ( & V_2 -> V_59 ) ;
V_2 -> V_20 . V_23 -= 1 ;
F_13 ( & V_2 -> V_59 ) ;
}
F_19 ( V_2 ) ;
return V_42 ;
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_27 ,
struct V_28 * V_29 )
{
int V_30 = V_31 ;
if ( V_4 -> V_7 & V_32 )
return V_31 ;
if ( ! V_27 && F_1 ( V_2 , V_4 ) )
V_30 |= V_33 ;
if ( V_4 -> V_7 & V_36 )
return V_30 ;
if ( V_4 -> free + V_4 -> V_17 != V_2 -> V_37 )
return V_30 ;
V_29 -> V_40 = V_4 -> V_40 ;
return V_33 | V_41 ;
}
static const struct V_3 * F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_28 V_29 ;
int V_42 ;
V_29 . V_40 = - 1 ;
V_42 = F_6 ( V_2 , - 1 , V_2 -> V_48 ,
( V_49 ) F_25 ,
& V_29 ) ;
if ( V_42 )
return F_5 ( V_42 ) ;
F_7 ( V_29 . V_40 >= V_2 -> V_50 && V_29 . V_40 < V_2 -> V_51 ) ;
V_2 -> V_48 = V_29 . V_40 ;
V_4 = F_8 ( V_2 , V_29 . V_40 ) ;
if ( F_9 ( V_4 ) )
return V_4 ;
F_7 ( V_4 -> V_40 == V_29 . V_40 ) ;
F_7 ( V_4 -> free + V_4 -> V_17 == V_2 -> V_37 ) ;
F_7 ( ! ( V_4 -> V_7 & V_32 ) ) ;
F_7 ( ! ( V_4 -> V_7 & V_36 ) ) ;
return V_4 ;
}
int F_27 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
int V_40 = - 1 , V_42 , V_7 ;
F_11 ( V_2 ) ;
V_4 = F_14 ( V_2 ) ;
if ( ! V_4 ) {
V_4 = F_15 ( V_2 ) ;
if ( ! V_4 ) {
if ( V_2 -> V_70 != V_2 -> V_71 ||
V_2 -> V_20 . V_21 - V_2 -> V_20 . V_23 > 0 ) {
F_7 ( V_2 -> V_22 == 0 ) ;
V_4 = F_26 ( V_2 ) ;
if ( F_9 ( V_4 ) ) {
V_42 = F_17 ( V_4 ) ;
goto V_66;
}
}
}
}
if ( ! V_4 ) {
V_42 = - V_47 ;
goto V_66;
}
V_40 = V_4 -> V_40 ;
F_16 ( L_2 ,
V_40 , V_4 -> free , V_4 -> V_17 , V_4 -> V_7 ) ;
V_7 = V_4 -> V_7 | V_32 | V_36 ;
V_4 = F_18 ( V_2 , V_4 , V_2 -> V_37 , 0 , V_7 , 0 ) ;
if ( F_9 ( V_4 ) ) {
V_42 = F_17 ( V_4 ) ;
goto V_66;
}
F_19 ( V_2 ) ;
V_42 = F_24 ( V_2 , V_40 ) ;
if ( V_42 ) {
F_28 ( V_2 , V_40 , V_67 , V_67 , 0 ,
V_32 | V_36 , 0 ) ;
return V_42 ;
}
return V_40 ;
V_66:
F_19 ( V_2 ) ;
return V_42 ;
}
static int F_29 ( const struct V_3 * * V_72 ,
const struct V_3 * * V_73 )
{
const struct V_3 * V_74 = * V_72 ;
const struct V_3 * V_75 = * V_73 ;
return V_74 -> V_17 + V_74 -> free - V_75 -> V_17 - V_75 -> free ;
}
static void F_30 ( struct V_3 * * V_72 , struct V_3 * * V_73 ,
int V_76 )
{
struct V_3 * V_77 = * V_72 ;
* V_72 = * V_73 ;
* V_73 = V_77 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_43 ;
F_11 ( V_2 ) ;
V_2 -> V_78 . V_15 = V_2 -> V_14 [ V_12 - 1 ] . V_15 ;
memcpy ( V_2 -> V_78 . V_44 , V_2 -> V_14 [ V_12 - 1 ] . V_44 ,
sizeof( void * ) * V_2 -> V_78 . V_15 ) ;
F_32 ( V_2 -> V_78 . V_44 , V_2 -> V_78 . V_15 , sizeof( void * ) ,
( int ( * ) ( const void * , const void * ) ) F_29 ,
( void ( * ) ( void * , void * , int ) ) F_30 ) ;
F_16 ( L_5 , V_2 -> V_78 . V_15 ) ;
if ( V_2 -> V_78 . V_15 )
F_16 ( L_6 ,
V_2 -> V_78 . V_44 [ V_2 -> V_78 . V_15 - 1 ] -> V_40 ,
V_2 -> V_78 . V_44 [ V_2 -> V_78 . V_15 - 1 ] -> V_17 ,
V_2 -> V_78 . V_44 [ V_2 -> V_78 . V_15 - 1 ] -> free ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_78 . V_15 ; V_43 ++ )
V_2 -> V_78 . V_44 [ V_43 ] = ( void * ) ( V_79 ) V_2 -> V_78 . V_44 [ V_43 ] -> V_40 ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_27 ,
struct V_28 * V_29 )
{
int V_30 = V_31 ;
if ( V_4 -> V_7 & V_32 )
return V_31 ;
if ( ! V_27 && F_1 ( V_2 , V_4 ) )
V_30 |= V_33 ;
if ( ! ( V_4 -> V_7 & V_36 ) )
return V_30 ;
if ( V_4 -> free + V_4 -> V_17 < V_2 -> V_80 )
return V_30 ;
V_29 -> V_40 = V_4 -> V_40 ;
return V_33 | V_41 ;
}
static int F_34 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_9 * V_10 ;
struct V_28 V_29 ;
int V_42 , V_43 , V_30 ;
V_29 . V_40 = - 1 ;
V_10 = & V_2 -> V_14 [ V_12 - 1 ] ;
for ( V_43 = 0 ; V_43 < V_10 -> V_15 ; V_43 ++ ) {
V_4 = V_10 -> V_44 [ V_43 ] ;
V_30 = F_33 ( V_2 , V_4 , 1 , & V_29 ) ;
if ( V_30 & V_41 )
goto V_64;
}
F_4 (lprops, &c->frdi_idx_list, list) {
V_30 = F_33 ( V_2 , V_4 , 1 , & V_29 ) ;
if ( V_30 & V_41 )
goto V_64;
}
F_4 (lprops, &c->uncat_list, list) {
V_30 = F_33 ( V_2 , V_4 , 1 , & V_29 ) ;
if ( V_30 & V_41 )
goto V_64;
}
if ( V_2 -> V_45 >= V_2 -> V_46 )
return - V_47 ;
V_42 = F_6 ( V_2 , - 1 , V_2 -> V_48 ,
( V_49 ) F_33 ,
& V_29 ) ;
if ( V_42 )
return V_42 ;
V_64:
F_7 ( V_29 . V_40 >= V_2 -> V_50 && V_29 . V_40 < V_2 -> V_51 ) ;
V_2 -> V_48 = V_29 . V_40 ;
V_4 = F_8 ( V_2 , V_29 . V_40 ) ;
if ( F_9 ( V_4 ) )
return F_17 ( V_4 ) ;
F_7 ( V_4 -> V_40 == V_29 . V_40 ) ;
F_7 ( V_4 -> free + V_4 -> V_17 >= V_2 -> V_80 ) ;
F_7 ( ! ( V_4 -> V_7 & V_32 ) ) ;
F_7 ( ( V_4 -> V_7 & V_36 ) ) ;
F_16 ( L_7 ,
V_4 -> V_40 , V_4 -> free , V_4 -> V_17 , V_4 -> V_7 ) ;
V_4 = F_18 ( V_2 , V_4 , V_67 , V_67 ,
V_4 -> V_7 | V_32 , 0 ) ;
if ( F_9 ( V_4 ) )
return F_17 ( V_4 ) ;
return V_4 -> V_40 ;
}
static int F_35 ( struct V_1 * V_2 )
{
const struct V_3 * V_54 ;
int V_42 , V_40 ;
V_42 = F_36 ( V_2 ) ;
if ( V_42 < 0 )
return V_42 ;
V_40 = V_42 ;
V_54 = F_8 ( V_2 , V_40 ) ;
if ( F_9 ( V_54 ) )
return F_17 ( V_54 ) ;
V_54 = F_18 ( V_2 , V_54 , V_67 , V_67 ,
V_54 -> V_7 | V_36 , - 1 ) ;
if ( F_9 ( V_54 ) )
return F_17 ( V_54 ) ;
F_16 ( L_8 ,
V_54 -> V_40 , V_54 -> V_17 , V_54 -> free , V_54 -> V_7 ) ;
return V_40 ;
}
static int F_37 ( struct V_1 * V_2 )
{
const struct V_3 * V_54 ;
int V_40 ;
while ( 1 ) {
if ( ! V_2 -> V_78 . V_15 )
return - V_47 ;
V_40 = ( V_79 ) V_2 -> V_78 . V_44 [ -- V_2 -> V_78 . V_15 ] ;
V_54 = F_38 ( V_2 , V_40 ) ;
if ( F_9 ( V_54 ) )
return F_17 ( V_54 ) ;
if ( ( V_54 -> V_7 & V_32 ) || ! ( V_54 -> V_7 & V_36 ) )
continue;
V_54 = F_18 ( V_2 , V_54 , V_67 , V_67 ,
V_54 -> V_7 | V_32 , 0 ) ;
if ( F_9 ( V_54 ) )
return F_17 ( V_54 ) ;
break;
}
F_16 ( L_8 , V_54 -> V_40 , V_54 -> V_17 ,
V_54 -> free , V_54 -> V_7 ) ;
F_7 ( V_54 -> V_7 & V_32 ) ;
F_7 ( V_54 -> V_7 & V_36 ) ;
return V_40 ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_42 ;
F_11 ( V_2 ) ;
V_42 = F_37 ( V_2 ) ;
if ( V_42 == - V_47 )
V_42 = F_34 ( V_2 ) ;
if ( V_42 == - V_47 )
V_42 = F_35 ( V_2 ) ;
F_19 ( V_2 ) ;
return V_42 ;
}
